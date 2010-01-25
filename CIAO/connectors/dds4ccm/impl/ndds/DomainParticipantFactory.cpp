// $Id$

#include "DomainParticipantFactory.h"
#include "DomainParticipant.h"
#include "DomainParticipantListener.h"
#include "Utils.h"

#include "ciao/Logger/Log_Macros.h"
#include "dds4ccm/idl/dds4ccm_BaseC.h"

namespace CIAO
{
  namespace DDS4CCM
  {
    namespace RTI
    {
       RTI_DomainParticipantFactory_i::RTI_DomainParticipantFactory_i (void)
       {
         CIAO_TRACE ("RTI_DomainParticipantFactory_i::RTI_DomainParticipantFactory_i");
       }

       RTI_DomainParticipantFactory_i::~RTI_DomainParticipantFactory_i (void)
       {
         CIAO_TRACE ("RTI_DomainParticipantFactory_i::~RTI_DomainParticipantFactory_i");
       }

      ::DDS::DomainParticipant_ptr
      RTI_DomainParticipantFactory_i::create_participant (::DDS::DomainId_t domain_id,
                                                          const ::DDS::DomainParticipantQos & /*qos*/,
                                                          ::DDS::DomainParticipantListener_ptr a_listener,
                                                          ::DDS::StatusMask mask)
      {
        CIAO_TRACE ("RTI_DomainParticipantFactory_i::create_participant");

        CIAO_DEBUG (9, (LM_TRACE, CLINFO "RTI_DomainParticipantFactory_i::create_participant - "
                     "Creating domain participant\n"));

        RTI_DomainParticipantListener_i *rti_dpl = 0;
        if (!CORBA::is_nil (a_listener))
          {
            rti_dpl = new RTI_DomainParticipantListener_i (a_listener);
          }

        DDSDomainParticipant *part = DDSDomainParticipantFactory::get_instance ()->
          create_participant (domain_id,
                              DDS_PARTICIPANT_QOS_DEFAULT,
                              rti_dpl,
                              mask);

        if (!part)
          {
            CIAO_ERROR (1, (LM_ERROR, CLINFO "RTI_DomainParticipantFactory_i::create_participant - "
                         "Error: Unable to create DomainParticipant\n"));
            throw CCM_DDS::InternalError (1, 0);
          }

        part->enable ();
        ::DDS::DomainParticipant_var retval = new RTI_DomainParticipant_i ();
        RTI_DomainParticipant_i *rti_dp = dynamic_cast < RTI_DomainParticipant_i *> (retval.in ());
        rti_dp->set_impl (part);

        return retval._retn ();
      }


      ::DDS::DomainParticipant_ptr
      RTI_DomainParticipantFactory_i::create_participant_with_profile (
        ::DDS::DomainId_t domain_id,
        const char * library_name,
        const char * profile_name,
        ::DDS::DomainParticipantListener_ptr a_listener,
        ::DDS::StatusMask mask)
      {
        CIAO_TRACE ("RTI_DomainParticipantFactory_i::create_participant_with_profile");

        CIAO_DEBUG (9, (LM_TRACE, CLINFO "RTI_DomainParticipantFactory_i::create_participant_with_profile - "
                     "Creating domain participant\n"));
        RTI_DomainParticipantListener_i *rti_dpl = 0;
        if (!CORBA::is_nil (a_listener))
          {
            rti_dpl = new RTI_DomainParticipantListener_i (a_listener);
          }

        ACE_CString qos_profile = library_name;
        qos_profile += ACE_TEXT ("#");
        qos_profile += profile_name;

        DDSDomainParticipant * part = 0;
        {
          ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX, _guard,
                          this->dps_mutex_, CORBA::INTERNAL ());
          part = this->dps_[qos_profile];
          if (!part)
            {
              part = DDSDomainParticipantFactory::get_instance ()->
                create_participant_with_profile (domain_id,
                                  library_name,
                                  profile_name,
                                  rti_dpl,
                                  mask);
              if (!part)
                {
                  CIAO_ERROR (1, (LM_ERROR, CLINFO "RTI_DomainParticipantFactory_i::create_participant_with_profile - "
                              "Error: Unable to create DomainParticipant\n"));
                  throw CCM_DDS::InternalError (1, 0);
                }
              part->enable ();
            }
          else CIAO_DEBUG (9, (LM_TRACE, CLINFO "RTI_DomainParticipantFactory_i::create_participant_with_profile - "
                          "Re-using participant for %C.\n",
                          qos_profile.c_str ()));

          ::DDS::DomainParticipant_var retval = new RTI_DomainParticipant_i ();
          RTI_DomainParticipant_i *rti_dp = dynamic_cast < RTI_DomainParticipant_i *> (retval.in ());
          rti_dp->set_impl (part);

          this->dps_[qos_profile] = part;

          return retval._retn ();
        }
      }

      void
      RTI_DomainParticipantFactory_i::remove_participant (DDSDomainParticipant * part)
      {
        CIAO_TRACE ("RTI_DomainParticipantFactory_i::remove_participant");
        ACE_GUARD_THROW_EX (TAO_SYNCH_MUTEX, _guard,
                        this->dps_mutex_, CORBA::INTERNAL ());

        DomainParticipants::iterator pos;
        for (pos = this->dps_.begin(); pos != this->dps_.end(); ++pos)
          {
            if (pos->second == part)
              {
                CIAO_DEBUG (9, (LM_TRACE, CLINFO "RTI_DomainParticipantFactory_i::remove_participant - "
                          "Deleting participant for %C.\n",
                          pos->first.c_str ()));
                this->dps_.erase (pos->first);
                break;
              }
          }
      }

      ::DDS::ReturnCode_t
      RTI_DomainParticipantFactory_i::delete_participant (::DDS::DomainParticipant_ptr a_participant)
      {
        CIAO_TRACE ("RTI_DomainParticipantFactory_i::delete_participant");

        RTI_DomainParticipant_i *part = dynamic_cast< RTI_DomainParticipant_i * > (a_participant);

        if (!part)
          {
            CIAO_ERROR (1, (LM_ERROR, CLINFO "RTI_DomainParticipantFactory_i::delete_participant - "
                         "Unable to cast provided object reference to servant type, bailing.\n"));
            return DDS::RETCODE_ERROR;
          }
        CIAO_DEBUG (9, (LM_TRACE, CLINFO "RTI_DomainParticipantFactory_i::delete_participant - "
                     "Successfully casted provided object reference to servant type.\n"));

        this->remove_participant (part->get_impl ());

        DDS_ReturnCode_t const retval = DDSDomainParticipantFactory::get_instance ()->
            delete_participant (part->get_impl ());

        if (retval != DDS_RETCODE_OK)
          {
            CIAO_ERROR (1, (LM_ERROR, CLINFO "RTI_DomainParticipantFactory_i::delete_participant - "
                         "RTI delete_participant returned non-ok error code %C\n",
                         translate_retcode (retval)));
          }
        else CIAO_DEBUG (6, (LM_INFO, CLINFO "RTI_DomainParticipantFactory_i::delete_participant - "
                          "Successfully deleted provided participant.\n"));

        return retval;
      }

      ::DDS::DomainParticipant_ptr
      RTI_DomainParticipantFactory_i::lookup_participant (::DDS::DomainId_t domain_id)
      {
        DDSDomainParticipant* dp = DDSDomainParticipantFactory::get_instance ()->lookup_participant (domain_id);
        ::DDS::DomainParticipant_var retval = new RTI_DomainParticipant_i ();
        RTI_DomainParticipant_i *rti_dp = dynamic_cast < RTI_DomainParticipant_i *> (retval.in ());
        rti_dp->set_impl (dp);
        return retval._retn ();
      }

      ::DDS::ReturnCode_t
      RTI_DomainParticipantFactory_i::set_default_participant_qos (const ::DDS::DomainParticipantQos & /*qos*/)
      {
        CIAO_TRACE ("RTI_DomainParticipantFactory_i::set_default_participant_qos");

        throw CORBA::NO_IMPLEMENT ();
      }

      ::DDS::ReturnCode_t
      RTI_DomainParticipantFactory_i::get_default_participant_qos (::DDS::DomainParticipantQos & /*qos*/)
      {
        CIAO_TRACE ("RTI_DomainParticipantFactory_i::get_default_participant_qos");

        throw CORBA::NO_IMPLEMENT ();
      }

      ::DDS::ReturnCode_t
      RTI_DomainParticipantFactory_i::set_qos (const ::DDS::DomainParticipantFactoryQos & /*qos*/)
      {
        CIAO_TRACE ("RTI_DomainParticipantFactory_i::set_qos");

        throw CORBA::NO_IMPLEMENT ();
      }

      ::DDS::ReturnCode_t
      RTI_DomainParticipantFactory_i::get_qos (::DDS::DomainParticipantFactoryQos & /*qos*/)
      {
        CIAO_TRACE ("RTI_DomainParticipantFactory_i::get_qos");

        throw CORBA::NO_IMPLEMENT ();
      }

      ::DDS::ReturnCode_t
      RTI_DomainParticipantFactory_i::set_default_participant_qos_with_profile (
                                                          const char * library_name,
                                                          const char * profile_name)
      {
        CIAO_TRACE ("RTI_DomainParticipantFactory_i::set_default_participant_qos_with_profile");

        return DDSDomainParticipantFactory::get_instance ()->set_default_participant_qos_with_profile (library_name, profile_name);
      }
    }
  }
}

#if defined (ACE_HAS_EXPLICIT_STATIC_TEMPLATE_MEMBER_INSTANTIATION)
template ACE_Singleton<CIAO::DDS4CCM::RTI::RTI_DomainParticipantFactory_i, TAO_SYNCH_MUTEX> *
         ACE_Singleton<CIAO::DDS4CCM::RTI::RTI_DomainParticipantFactory_i, TAO_SYNCH_MUTEX>::singleton_;
#endif /* ACE_HAS_EXPLICIT_STATIC_TEMPLATE_MEMBER_INSTANTIATION */
