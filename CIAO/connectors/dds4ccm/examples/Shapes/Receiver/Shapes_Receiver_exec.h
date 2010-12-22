// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.0.0
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
#ifndef CIAO_SHAPES_RECEIVER_EXEC_4YQX0E_H_
#define CIAO_SHAPES_RECEIVER_EXEC_4YQX0E_H_

#include /**/ "ace/pre.h"

#include "Shapes_ReceiverEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Receiver_exec_export.h"
#include "tao/LocalObject.h"

namespace CIAO_Shapes_Receiver_Impl
{
  class Receiver_exec_i;

  /**
  * @class reader activity generator
  *
  * @brief an active object used by Receiver to perform a periodical read action
  *
  */
  class read_action_Generator
    : public ACE_Event_Handler
  {
  public:
    read_action_Generator (Receiver_exec_i &callback);

    ~read_action_Generator ();

    virtual int handle_timeout (const ACE_Time_Value &tv,
                                const void *arg);

  private:
    Receiver_exec_i &pulse_callback_;

  };

  /**
   * Provider Executor Implementation Class: info_out_data_listener_exec_i
   */

  class info_out_data_listener_exec_i
    : public virtual ::Shapes::CCM_Listener,
      public virtual ::CORBA::LocalObject
  {
  public:
    info_out_data_listener_exec_i (
      ::Shapes::CCM_Receiver_Context_ptr ctx);
    virtual ~info_out_data_listener_exec_i (void);

    //@{
    /** Operations and attributes from ::Shapes::Listener. */

    virtual
    void on_one_data (const ::ShapeType & datum,
    const ::CCM_DDS::ReadInfo & info);

    virtual
    void on_many_data (const ::ShapeTypeSeq & data,
    const ::CCM_DDS::ReadInfoSeq & infos);
    //@}

  private:
    ::Shapes::CCM_Receiver_Context_var ciao_context_;
  };

  /**
   * Provider Executor Implementation Class: info_out_status_exec_i
   */

  class info_out_status_exec_i
    : public virtual ::CCM_DDS::CCM_PortStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    info_out_status_exec_i (
      ::Shapes::CCM_Receiver_Context_ptr ctx);
    virtual ~info_out_status_exec_i (void);

    //@{
    /** Operations and attributes from ::CCM_DDS::PortStatusListener. */

    virtual
    void on_requested_deadline_missed (::DDS::DataReader_ptr the_reader,
    const ::DDS::RequestedDeadlineMissedStatus & status);

    virtual
    void on_sample_lost (::DDS::DataReader_ptr the_reader,
    const ::DDS::SampleLostStatus & status);
    //@}

  private:
    ::Shapes::CCM_Receiver_Context_var ciao_context_;
  };

  /**
   * Provider Executor Implementation Class: info_get_status_exec_i
   */

  class info_get_status_exec_i
    : public virtual ::CCM_DDS::CCM_PortStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    info_get_status_exec_i (
      ::Shapes::CCM_Receiver_Context_ptr ctx);
    virtual ~info_get_status_exec_i (void);

    //@{
    /** Operations and attributes from ::CCM_DDS::PortStatusListener. */

    virtual
    void on_requested_deadline_missed (::DDS::DataReader_ptr the_reader,
    const ::DDS::RequestedDeadlineMissedStatus & status);

    virtual
    void on_sample_lost (::DDS::DataReader_ptr the_reader,
    const ::DDS::SampleLostStatus & status);
    //@}

  private:
    ::Shapes::CCM_Receiver_Context_var ciao_context_;
  };

  /**
   * Component Executor Implementation Class: Receiver_exec_i
   */

  class Receiver_exec_i
    : public virtual Receiver_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Receiver_exec_i (void);
    virtual ~Receiver_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */

    virtual ::Shapes::CCM_Listener_ptr
    get_info_out_data_listener (void);

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_info_out_status (void);

    virtual ::CCM_DDS::CCM_PortStatusListener_ptr
    get_info_get_status (void);

    virtual ::CORBA::ULong rate (void);

    virtual void rate (::CORBA::ULong rate);

    virtual ::CORBA::Boolean get_data (void);

    virtual void get_data (::CORBA::Boolean get_data);

    virtual ::CORBA::Boolean read_data (void);

    virtual void read_data (::CORBA::Boolean read_data);

    virtual ::CORBA::Boolean raw_listen (void);

    virtual void raw_listen (::CORBA::Boolean raw_listen);
    //@}

    //@{
    /** Operations from Components::SessionComponent. */
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    virtual void configuration_complete (void);
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    //@{
    /** User defined public operations. */
    void read_one (void);
    void read_all (void);
    void get_one (void);

    //@}

  private:
    ::Shapes::CCM_Receiver_Context_var ciao_context_;

    //@{
    /** Component attributes. */
    ::Shapes::CCM_Listener_var ciao_info_out_data_listener_;
    ::CCM_DDS::CCM_PortStatusListener_var ciao_info_out_status_;
    ::CCM_DDS::CCM_PortStatusListener_var ciao_info_get_status_;

    ::CORBA::ULong rate_;

    ::CORBA::Boolean get_data_;

    ::CORBA::Boolean read_data_;

    ::CORBA::Boolean raw_listen_;
    //@}

    //@{
    /** User defined members. */
    read_action_Generator * ticker_;

    //@}

    //@{
    /** User defined private operations. */

    //@}

    /// Get the ACE_Reactor
    ACE_Reactor* reactor (void);
  };

  extern "C" RECEIVER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Shapes_Receiver_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
