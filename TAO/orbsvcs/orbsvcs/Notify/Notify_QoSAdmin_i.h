/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   Notify_QoSAdmin_i.h
 *
 *  $Id$
 *
 * Implements get/set methods for QoS properties.
 *
 *
 *  @author Pradeep Gore <pradeep@cs.wustl.edu>
 */
//=============================================================================

#ifndef TAO_NOTIFY_QOSADMIN_I_H
#define TAO_NOTIFY_QOSADMIN_I_H
#include "ace/pre.h"

#include "orbsvcs/CosNotificationC.h"
#include "orbsvcs/TimeBaseC.h"

#include "notify_export.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

/**
 * @class TAO_Notify_QoSAdmin_i
 *
 * @brief TAO_Notify_QoSAdmin_i
 *
 */
class TAO_Notify_Export TAO_Notify_QoSAdmin_i
{
public:
  /// Constructor
  TAO_Notify_QoSAdmin_i (void);

  /// Destructor
  virtual ~TAO_Notify_QoSAdmin_i (void);

  virtual CosNotification::QoSProperties * get_qos (
    ACE_ENV_SINGLE_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ));

  virtual void set_qos (
    const CosNotification::QoSProperties & qos
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    CosNotification::UnsupportedQoS
  ));

  virtual void validate_qos (
    const CosNotification::QoSProperties & required_qos,
    CosNotification::NamedPropertyRangeSeq_out available_qos
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException,
    CosNotification::UnsupportedQoS
  ));

  // Accessors
  CORBA::Long     maximum_batch_size (void) const;
  TimeBase::TimeT pacing_interval (void) const;

protected:
  // = QoS Properties
  CORBA::Short event_reliability_;
  CORBA::Boolean event_reliability_set_;

  /// Reliability properties (to be implemented "later").
  CORBA::Short connection_reliability_;
  CORBA::Boolean connection_reliability_set_;

  /// Priority for the event
  CORBA::Short priority_;
  CORBA::Boolean priority_set_;

  /// Earliest delivery time
  /*
  TimeBase::UtcT start_time_;

  TimeBase::UtcT stop_time_;

  */

  /// Expiry time
  TimeBase::TimeT timeout_;
  CORBA::Boolean timeout_set_;

  CORBA::Boolean start_time_supported_;
  CORBA::Boolean start_time_supported_set_;

  /// Are start/stop times supported
  CORBA::Boolean stop_time_supported_;
  CORBA::Boolean stop_time_supported_set_;

  /// Max events allowed to be queued on behalf of a consumer
  CORBA::Long max_events_per_consumer_;
  CORBA::Boolean max_events_per_consumer_set_;

  /// Order of events in internal buffers.
  CORBA::Short order_policy_;
  CORBA::Boolean order_policy_set_;

  /// Policy to discard when buffers are full.
  CORBA::Short discard_policy_;
  CORBA::Boolean discard_policy_set_;

  /// Batch size for sequences of structured events.
  CORBA::Long maximum_batch_size_;
  CORBA::Boolean maximum_batch_size_set_;

  /// Max. period of time that events are collected before delivering
  /// them as a sequence of structured events.
  TimeBase::TimeT pacing_interval_;
  CORBA::Boolean pacing_interval_set_;

  // TAO Specific QoS Properties
  ///
  TimeBase::TimeT blocking_timeout_;
  CORBA::Boolean blocking_timeout_set_;
};

#if defined (__ACE_INLINE__)
#include "Notify_QoSAdmin_i.inl"
#endif /* __ACE_INLINE__ */

#include "ace/post.h"
#endif /* TAO_NOTIFY_QOSADMIN_I_H */
