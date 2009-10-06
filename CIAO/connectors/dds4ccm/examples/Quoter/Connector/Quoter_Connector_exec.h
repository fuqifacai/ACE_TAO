// -*- C++ -*-
//
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v1.7.2
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 *       http://doc.ece.uci.edu/
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:1217

#ifndef CIAO_QUOTER_CONNECTOR_EXEC_H_
#define CIAO_QUOTER_CONNECTOR_EXEC_H_

#include /**/ "ace/pre.h"

#include "Quoter_ConnectorEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Quoter_Connector_exec_export.h"
#include "tao/LocalObject.h"

#include "dds4ccm/impl/ndds/NDDS_Traits.h"
#include "dds4ccm/impl/ndds/DataWriter.h"
#include "dds4ccm/impl/ndds/Writer.h"
#include "Base/Quoter_BaseSupport.h"

namespace CIAO_Quoter_Quoter_Connector_Impl
{
  class QUOTER_CONNECTOR_EXEC_Export Stock_Info_Reader_exec_i
    : public virtual ::CCM_DDS::CCM_Stock_Info_Reader,
      public virtual ::CORBA::LocalObject
  {
  public:
    Stock_Info_Reader_exec_i (void);
    virtual ~Stock_Info_Reader_exec_i (void);
    
    // Operations and attributes from ::CCM_DDS::Stock_Info_Reader
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    read_all (
      ::CCM_DDS::Stock_Info_Reader::Stock_InfoSeq_out instances,
      ::CCM_DDS::ReadInfoSeq_out infos);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    read_all_history (
      ::CCM_DDS::Stock_Info_Reader::Stock_InfoSeq_out instances,
      ::CCM_DDS::ReadInfoSeq_out infos);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    read_one (
      ::Quoter::Stock_Info & an_instance,
      ::CCM_DDS::ReadInfo_out info);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    read_one_history (
      const ::Quoter::Stock_Info & an_instance,
      ::CCM_DDS::Stock_Info_Reader::Stock_InfoSeq_out instances,
      ::CCM_DDS::ReadInfoSeq_out infos);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::CCM_DDS::QueryFilter *
    filter (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    filter (
      const ::CCM_DDS::QueryFilter & filter);
  };
  
  class QUOTER_CONNECTOR_EXEC_Export Quoter_Connector_exec_i
    : public virtual Quoter_Connector_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Quoter_Connector_exec_i (void);
    virtual ~Quoter_Connector_exec_i (void);
    
    // Supported operations and attributes.
    
    // Component attributes.
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual char *
    topic_name (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    topic_name (
      const char * topic_name);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::StringSeq *
    key_fields (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    key_fields (
      const ::DDS::StringSeq & key_fields);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual ::DDS::DomainId_t
    domain_id (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    domain_id (
      ::DDS::DomainId_t domain_id);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual char *
    qos_profile (void);
    
    // TAO_IDL - Generated from
    // be/be_visitor_operation/operation_ch.cpp:46
    
    virtual void
    qos_profile (
      const char * qos_profile);
    
    // Port operations.
    
    virtual ::CCM_DDS::CCM_Stock_Info_Writer_ptr
    get_info_in_data (void);
    
    virtual ::DDS::CCM_DataWriter_ptr
    get_info_in_dds_entity (void);
    
    virtual ::CCM_DDS::CCM_Stock_Info_Reader_ptr
    get_info_out_data (void);
    
    virtual ::CCM_DDS::CCM_ListenerControl_ptr
    get_info_out_control (void);
    
    virtual ::DDS::CCM_DataReader_ptr
    get_info_out_dds_entity (void);
    
    // Operations from Components::SessionComponent.
    
    virtual void
    set_session_context (
      ::Components::SessionContext_ptr ctx);
    
    virtual void configuration_complete (void);
    
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
  
  private:
    ::Quoter::CCM_Quoter_Connector_Context_var context_;

    // @from use of Stock_Info as a parameter
    typedef CIAO::DDS4CCM::RTI::Type_Traits < ::Quoter::Stock_Info,
      ::Quoter::Stock_InfoSeq,
      ::Quoter::Stock_InfoTypeSupport,
      ::Quoter::Stock_InfoDataWriter,
      ::Quoter::Stock_InfoDataReader > Stock_Info_Traits;

    // Default stuff
    void configure_default_domain_ (void);
    bool default_domain_configured_;
    ::DDS::DomainParticipantFactory_var domain_factory_;
    ::DDS::DomainParticipant_var domain_;

    // @from DDS_Base
    CCM_DDS::ConnectorStatusListener_var error_listener_;
    DDS::DomainId_t domain_id_;
    CORBA::String_var qos_profile_;
    
    
    // @from DDS_TopicBase
    void configure_default_topic_ (void);
    bool default_topic_configured_;
    ::DDS::Topic_var topic_;
    CORBA::String_var topic_name_;
    DDS::StringSeq key_fields_;
    
    // @from DDS_Write for Stock_Info
    void configure_port_info_in_ (void);
    bool __info_in_configured_;
    ::DDS::Publisher_var __info_in_publisher_;
    ::DDS::CCM_DataWriter_var __info_in_datawriter_;
    ::CCM_DDS::CCM_Stock_Info_Writer_var __info_in_writer_;

    // @from DDS_RawListen
    void configure_port_info_out_ (void);
    bool __info_out_configured_;
    CCM_DDS::Stock_Info_RawListener_var __info_out_rawlistener_;
    ACE_Atomic_Op <TAO_SYNCH_MUTEX, bool> __info_out_rawlistener_enabled_;
    CCM_DDS::PortStatusListener_var __info_out_portstatus_;
    ::DDS::Subscriber_var __info_out_subscriber_;
    ::DDS::DataReaderListener_var __info_out_listener_;
    ::DDS::DataReader_var __info_out_datareader_;
    ::DDS::DataReaderListener_var __info_out_datareaderlistener;
    
  };
  
  extern "C" QUOTER_CONNECTOR_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Quoter_Quoter_Connector_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */

