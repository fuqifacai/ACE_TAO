// $Id$
#include "cid.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    // SubcomponentInstantiationDescription
    // 

    SubcomponentInstantiationDescription::
    SubcomponentInstantiationDescription (::XMLSchema::string< char > const& name__,
    ::CIAO::Config_Handlers::ComponentPackageDescription const& package__)
    :
    name_ (new ::XMLSchema::string< char > (name__)),
    package_ (new ::CIAO::Config_Handlers::ComponentPackageDescription (package__)),
    regulator__ ()
    {
      name_->container (this);
      package_->container (this);
    }

    SubcomponentInstantiationDescription::
    SubcomponentInstantiationDescription (::CIAO::Config_Handlers::SubcomponentInstantiationDescription const& s)
    :
    name_ (new ::XMLSchema::string< char > (*s.name_)),
    package_ (new ::CIAO::Config_Handlers::ComponentPackageDescription (*s.package_)),
    configProperty_ (s.configProperty_.get () ? new ::CIAO::Config_Handlers::Property (*s.configProperty_) : 0),
    selectRequirement_ (s.selectRequirement_.get () ? new ::CIAO::Config_Handlers::Requirement (*s.selectRequirement_) : 0),
    reference_ (s.reference_.get () ? new ::CIAO::Config_Handlers::ComponentPackageReference (*s.reference_) : 0),
    id_ (s.id_.get () ? new ::XMLSchema::ID< char > (*s.id_) : 0),
    regulator__ ()
    {
      name_->container (this);
      package_->container (this);
      if (configProperty_.get ()) configProperty_->container (this);
      if (selectRequirement_.get ()) selectRequirement_->container (this);
      if (reference_.get ()) reference_->container (this);
      if (id_.get ()) id_->container (this);
    }

    ::CIAO::Config_Handlers::SubcomponentInstantiationDescription& SubcomponentInstantiationDescription::
    operator= (::CIAO::Config_Handlers::SubcomponentInstantiationDescription const& s)
    {
      name (s.name ());

      package (s.package ());

      if (s.configProperty_.get ()) configProperty (*(s.configProperty_));
      else configProperty_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (0);

      if (s.selectRequirement_.get ()) selectRequirement (*(s.selectRequirement_));
      else selectRequirement_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Requirement > (0);

      if (s.reference_.get ()) reference (*(s.reference_));
      else reference_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentPackageReference > (0);

      if (s.id_.get ()) id (*(s.id_));
      else id_ = ::std::auto_ptr< ::XMLSchema::ID< char > > (0);

      return *this;
    }


    // SubcomponentInstantiationDescription
    // 
    ::XMLSchema::string< char > const& SubcomponentInstantiationDescription::
    name () const
    {
      return *name_;
    }

    ::XMLSchema::string< char >& SubcomponentInstantiationDescription::
    name ()
    {
      return *name_;
    }

    void SubcomponentInstantiationDescription::
    name (::XMLSchema::string< char > const& e)
    {
      *name_ = e;
    }

    // SubcomponentInstantiationDescription
    // 
    ::CIAO::Config_Handlers::ComponentPackageDescription const& SubcomponentInstantiationDescription::
    package () const
    {
      return *package_;
    }

    ::CIAO::Config_Handlers::ComponentPackageDescription& SubcomponentInstantiationDescription::
    package ()
    {
      return *package_;
    }

    void SubcomponentInstantiationDescription::
    package (::CIAO::Config_Handlers::ComponentPackageDescription const& e)
    {
      *package_ = e;
    }

    // SubcomponentInstantiationDescription
    // 
    bool SubcomponentInstantiationDescription::
    configProperty_p () const
    {
      return configProperty_.get () != 0;
    }

    ::CIAO::Config_Handlers::Property const& SubcomponentInstantiationDescription::
    configProperty () const
    {
      return *configProperty_;
    }

    ::CIAO::Config_Handlers::Property& SubcomponentInstantiationDescription::
    configProperty ()
    {
      return *configProperty_;
    }

    void SubcomponentInstantiationDescription::
    configProperty (::CIAO::Config_Handlers::Property const& e)
    {
      if (configProperty_.get ())
      {
        *configProperty_ = e;
      }

      else
      {
        configProperty_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (new ::CIAO::Config_Handlers::Property (e));
        configProperty_->container (this);
      }
    }

    // SubcomponentInstantiationDescription
    // 
    bool SubcomponentInstantiationDescription::
    selectRequirement_p () const
    {
      return selectRequirement_.get () != 0;
    }

    ::CIAO::Config_Handlers::Requirement const& SubcomponentInstantiationDescription::
    selectRequirement () const
    {
      return *selectRequirement_;
    }

    ::CIAO::Config_Handlers::Requirement& SubcomponentInstantiationDescription::
    selectRequirement ()
    {
      return *selectRequirement_;
    }

    void SubcomponentInstantiationDescription::
    selectRequirement (::CIAO::Config_Handlers::Requirement const& e)
    {
      if (selectRequirement_.get ())
      {
        *selectRequirement_ = e;
      }

      else
      {
        selectRequirement_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Requirement > (new ::CIAO::Config_Handlers::Requirement (e));
        selectRequirement_->container (this);
      }
    }

    // SubcomponentInstantiationDescription
    // 
    bool SubcomponentInstantiationDescription::
    reference_p () const
    {
      return reference_.get () != 0;
    }

    ::CIAO::Config_Handlers::ComponentPackageReference const& SubcomponentInstantiationDescription::
    reference () const
    {
      return *reference_;
    }

    ::CIAO::Config_Handlers::ComponentPackageReference& SubcomponentInstantiationDescription::
    reference ()
    {
      return *reference_;
    }

    void SubcomponentInstantiationDescription::
    reference (::CIAO::Config_Handlers::ComponentPackageReference const& e)
    {
      if (reference_.get ())
      {
        *reference_ = e;
      }

      else
      {
        reference_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentPackageReference > (new ::CIAO::Config_Handlers::ComponentPackageReference (e));
        reference_->container (this);
      }
    }

    // SubcomponentInstantiationDescription
    // 
    bool SubcomponentInstantiationDescription::
    id_p () const
    {
      return id_.get () != 0;
    }

    ::XMLSchema::ID< char > const& SubcomponentInstantiationDescription::
    id () const
    {
      return *id_;
    }

    ::XMLSchema::ID< char >& SubcomponentInstantiationDescription::
    id ()
    {
      return *id_;
    }

    void SubcomponentInstantiationDescription::
    id (::XMLSchema::ID< char > const& e)
    {
      if (id_.get ())
      {
        *id_ = e;
      }

      else
      {
        id_ = ::std::auto_ptr< ::XMLSchema::ID< char > > (new ::XMLSchema::ID< char > (e));
        id_->container (this);
      }
    }


    // SubcomponentPropertyReference
    // 

    SubcomponentPropertyReference::
    SubcomponentPropertyReference (::XMLSchema::string< char > const& propertyName__,
    ::CIAO::Config_Handlers::SubcomponentInstantiationDescription const& instance__)
    :
    propertyName_ (new ::XMLSchema::string< char > (propertyName__)),
    instance_ (new ::CIAO::Config_Handlers::SubcomponentInstantiationDescription (instance__)),
    regulator__ ()
    {
      propertyName_->container (this);
      instance_->container (this);
    }

    SubcomponentPropertyReference::
    SubcomponentPropertyReference (::CIAO::Config_Handlers::SubcomponentPropertyReference const& s)
    :
    propertyName_ (new ::XMLSchema::string< char > (*s.propertyName_)),
    instance_ (new ::CIAO::Config_Handlers::SubcomponentInstantiationDescription (*s.instance_)),
    regulator__ ()
    {
      propertyName_->container (this);
      instance_->container (this);
    }

    ::CIAO::Config_Handlers::SubcomponentPropertyReference& SubcomponentPropertyReference::
    operator= (::CIAO::Config_Handlers::SubcomponentPropertyReference const& s)
    {
      propertyName (s.propertyName ());

      instance (s.instance ());

      return *this;
    }


    // SubcomponentPropertyReference
    // 
    ::XMLSchema::string< char > const& SubcomponentPropertyReference::
    propertyName () const
    {
      return *propertyName_;
    }

    ::XMLSchema::string< char >& SubcomponentPropertyReference::
    propertyName ()
    {
      return *propertyName_;
    }

    void SubcomponentPropertyReference::
    propertyName (::XMLSchema::string< char > const& e)
    {
      *propertyName_ = e;
    }

    // SubcomponentPropertyReference
    // 
    ::CIAO::Config_Handlers::SubcomponentInstantiationDescription const& SubcomponentPropertyReference::
    instance () const
    {
      return *instance_;
    }

    ::CIAO::Config_Handlers::SubcomponentInstantiationDescription& SubcomponentPropertyReference::
    instance ()
    {
      return *instance_;
    }

    void SubcomponentPropertyReference::
    instance (::CIAO::Config_Handlers::SubcomponentInstantiationDescription const& e)
    {
      *instance_ = e;
    }


    // AssemblyPropertyMapping
    // 

    AssemblyPropertyMapping::
    AssemblyPropertyMapping (::XMLSchema::string< char > const& name__,
    ::XMLSchema::string< char > const& externalName__,
    ::CIAO::Config_Handlers::SubcomponentPropertyReference const& delegatesTo__)
    :
    name_ (new ::XMLSchema::string< char > (name__)),
    externalName_ (new ::XMLSchema::string< char > (externalName__)),
    delegatesTo_ (new ::CIAO::Config_Handlers::SubcomponentPropertyReference (delegatesTo__)),
    regulator__ ()
    {
      name_->container (this);
      externalName_->container (this);
      delegatesTo_->container (this);
    }

    AssemblyPropertyMapping::
    AssemblyPropertyMapping (::CIAO::Config_Handlers::AssemblyPropertyMapping const& s)
    :
    name_ (new ::XMLSchema::string< char > (*s.name_)),
    externalName_ (new ::XMLSchema::string< char > (*s.externalName_)),
    delegatesTo_ (new ::CIAO::Config_Handlers::SubcomponentPropertyReference (*s.delegatesTo_)),
    regulator__ ()
    {
      name_->container (this);
      externalName_->container (this);
      delegatesTo_->container (this);
    }

    ::CIAO::Config_Handlers::AssemblyPropertyMapping& AssemblyPropertyMapping::
    operator= (::CIAO::Config_Handlers::AssemblyPropertyMapping const& s)
    {
      name (s.name ());

      externalName (s.externalName ());

      delegatesTo (s.delegatesTo ());

      return *this;
    }


    // AssemblyPropertyMapping
    // 
    ::XMLSchema::string< char > const& AssemblyPropertyMapping::
    name () const
    {
      return *name_;
    }

    ::XMLSchema::string< char >& AssemblyPropertyMapping::
    name ()
    {
      return *name_;
    }

    void AssemblyPropertyMapping::
    name (::XMLSchema::string< char > const& e)
    {
      *name_ = e;
    }

    // AssemblyPropertyMapping
    // 
    ::XMLSchema::string< char > const& AssemblyPropertyMapping::
    externalName () const
    {
      return *externalName_;
    }

    ::XMLSchema::string< char >& AssemblyPropertyMapping::
    externalName ()
    {
      return *externalName_;
    }

    void AssemblyPropertyMapping::
    externalName (::XMLSchema::string< char > const& e)
    {
      *externalName_ = e;
    }

    // AssemblyPropertyMapping
    // 
    ::CIAO::Config_Handlers::SubcomponentPropertyReference const& AssemblyPropertyMapping::
    delegatesTo () const
    {
      return *delegatesTo_;
    }

    ::CIAO::Config_Handlers::SubcomponentPropertyReference& AssemblyPropertyMapping::
    delegatesTo ()
    {
      return *delegatesTo_;
    }

    void AssemblyPropertyMapping::
    delegatesTo (::CIAO::Config_Handlers::SubcomponentPropertyReference const& e)
    {
      *delegatesTo_ = e;
    }


    // ComponentAssemblyDescription
    // 

    ComponentAssemblyDescription::
    ComponentAssemblyDescription ()
    :
    regulator__ ()
    {
    }

    ComponentAssemblyDescription::
    ComponentAssemblyDescription (::CIAO::Config_Handlers::ComponentAssemblyDescription const& s)
    :
    externalProperty_ (s.externalProperty_.get () ? new ::CIAO::Config_Handlers::AssemblyPropertyMapping (*s.externalProperty_) : 0),
    regulator__ ()
    {
      instance_.reserve (s.instance_.size ());
      {
        for (instance_const_iterator i (s.instance_.begin ());
        i != s.instance_.end ();
        ++i) add_instance (*i);
      }

      connection_.reserve (s.connection_.size ());
      {
        for (connection_const_iterator i (s.connection_.begin ());
        i != s.connection_.end ();
        ++i) add_connection (*i);
      }

      if (externalProperty_.get ()) externalProperty_->container (this);
    }

    ::CIAO::Config_Handlers::ComponentAssemblyDescription& ComponentAssemblyDescription::
    operator= (::CIAO::Config_Handlers::ComponentAssemblyDescription const& s)
    {
      instance_.clear ();
      instance_.reserve (s.instance_.size ());
      {
        for (instance_const_iterator i (s.instance_.begin ());
        i != s.instance_.end ();
        ++i) add_instance (*i);
      }

      connection_.clear ();
      connection_.reserve (s.connection_.size ());
      {
        for (connection_const_iterator i (s.connection_.begin ());
        i != s.connection_.end ();
        ++i) add_connection (*i);
      }

      if (s.externalProperty_.get ()) externalProperty (*(s.externalProperty_));
      else externalProperty_ = ::std::auto_ptr< ::CIAO::Config_Handlers::AssemblyPropertyMapping > (0);

      return *this;
    }


    // ComponentAssemblyDescription
    // 
    ComponentAssemblyDescription::instance_iterator ComponentAssemblyDescription::
    begin_instance ()
    {
      return instance_.begin ();
    }

    ComponentAssemblyDescription::instance_iterator ComponentAssemblyDescription::
    end_instance ()
    {
      return instance_.end ();
    }

    ComponentAssemblyDescription::instance_const_iterator ComponentAssemblyDescription::
    begin_instance () const
    {
      return instance_.begin ();
    }

    ComponentAssemblyDescription::instance_const_iterator ComponentAssemblyDescription::
    end_instance () const
    {
      return instance_.end ();
    }

    void ComponentAssemblyDescription::
    add_instance (::CIAO::Config_Handlers::SubcomponentInstantiationDescription const& e)
    {
      if (instance_.capacity () < instance_.size () + 1)
      {
        ::std::vector< ::CIAO::Config_Handlers::SubcomponentInstantiationDescription > v;
        v.reserve (instance_.size () + 1);

        while (instance_.size ())
        {
          //@@ VC6
          ::CIAO::Config_Handlers::SubcomponentInstantiationDescription& t = instance_.back ();
          t.container (0);
          v.push_back (t);
          v.back ().container (this);
          instance_.pop_back ();
        }

        instance_.swap (v);
      }

      instance_.push_back (e);
      instance_.back ().container (this);
    }

    // ComponentAssemblyDescription
    // 
    ComponentAssemblyDescription::connection_iterator ComponentAssemblyDescription::
    begin_connection ()
    {
      return connection_.begin ();
    }

    ComponentAssemblyDescription::connection_iterator ComponentAssemblyDescription::
    end_connection ()
    {
      return connection_.end ();
    }

    ComponentAssemblyDescription::connection_const_iterator ComponentAssemblyDescription::
    begin_connection () const
    {
      return connection_.begin ();
    }

    ComponentAssemblyDescription::connection_const_iterator ComponentAssemblyDescription::
    end_connection () const
    {
      return connection_.end ();
    }

    void ComponentAssemblyDescription::
    add_connection (::CIAO::Config_Handlers::AssemblyConnectionDescription const& e)
    {
      if (connection_.capacity () < connection_.size () + 1)
      {
        ::std::vector< ::CIAO::Config_Handlers::AssemblyConnectionDescription > v;
        v.reserve (connection_.size () + 1);

        while (connection_.size ())
        {
          //@@ VC6
          ::CIAO::Config_Handlers::AssemblyConnectionDescription& t = connection_.back ();
          t.container (0);
          v.push_back (t);
          v.back ().container (this);
          connection_.pop_back ();
        }

        connection_.swap (v);
      }

      connection_.push_back (e);
      connection_.back ().container (this);
    }

    // ComponentAssemblyDescription
    // 
    bool ComponentAssemblyDescription::
    externalProperty_p () const
    {
      return externalProperty_.get () != 0;
    }

    ::CIAO::Config_Handlers::AssemblyPropertyMapping const& ComponentAssemblyDescription::
    externalProperty () const
    {
      return *externalProperty_;
    }

    ::CIAO::Config_Handlers::AssemblyPropertyMapping& ComponentAssemblyDescription::
    externalProperty ()
    {
      return *externalProperty_;
    }

    void ComponentAssemblyDescription::
    externalProperty (::CIAO::Config_Handlers::AssemblyPropertyMapping const& e)
    {
      if (externalProperty_.get ())
      {
        *externalProperty_ = e;
      }

      else
      {
        externalProperty_ = ::std::auto_ptr< ::CIAO::Config_Handlers::AssemblyPropertyMapping > (new ::CIAO::Config_Handlers::AssemblyPropertyMapping (e));
        externalProperty_->container (this);
      }
    }


    // MonolithicImplementationDescription
    // 

    MonolithicImplementationDescription::
    MonolithicImplementationDescription ()
    :
    regulator__ ()
    {
    }

    MonolithicImplementationDescription::
    MonolithicImplementationDescription (::CIAO::Config_Handlers::MonolithicImplementationDescription const& s)
    :
    execParameter_ (s.execParameter_.get () ? new ::CIAO::Config_Handlers::Property (*s.execParameter_) : 0),
    deployRequirement_ (s.deployRequirement_.get () ? new ::CIAO::Config_Handlers::ImplementationRequirement (*s.deployRequirement_) : 0),
    regulator__ ()
    {
      if (execParameter_.get ()) execParameter_->container (this);
      primaryArtifact_.reserve (s.primaryArtifact_.size ());
      {
        for (primaryArtifact_const_iterator i (s.primaryArtifact_.begin ());
        i != s.primaryArtifact_.end ();
        ++i) add_primaryArtifact (*i);
      }

      if (deployRequirement_.get ()) deployRequirement_->container (this);
    }

    ::CIAO::Config_Handlers::MonolithicImplementationDescription& MonolithicImplementationDescription::
    operator= (::CIAO::Config_Handlers::MonolithicImplementationDescription const& s)
    {
      if (s.execParameter_.get ()) execParameter (*(s.execParameter_));
      else execParameter_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (0);

      primaryArtifact_.clear ();
      primaryArtifact_.reserve (s.primaryArtifact_.size ());
      {
        for (primaryArtifact_const_iterator i (s.primaryArtifact_.begin ());
        i != s.primaryArtifact_.end ();
        ++i) add_primaryArtifact (*i);
      }

      if (s.deployRequirement_.get ()) deployRequirement (*(s.deployRequirement_));
      else deployRequirement_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ImplementationRequirement > (0);

      return *this;
    }


    // MonolithicImplementationDescription
    // 
    bool MonolithicImplementationDescription::
    execParameter_p () const
    {
      return execParameter_.get () != 0;
    }

    ::CIAO::Config_Handlers::Property const& MonolithicImplementationDescription::
    execParameter () const
    {
      return *execParameter_;
    }

    ::CIAO::Config_Handlers::Property& MonolithicImplementationDescription::
    execParameter ()
    {
      return *execParameter_;
    }

    void MonolithicImplementationDescription::
    execParameter (::CIAO::Config_Handlers::Property const& e)
    {
      if (execParameter_.get ())
      {
        *execParameter_ = e;
      }

      else
      {
        execParameter_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (new ::CIAO::Config_Handlers::Property (e));
        execParameter_->container (this);
      }
    }

    // MonolithicImplementationDescription
    // 
    MonolithicImplementationDescription::primaryArtifact_iterator MonolithicImplementationDescription::
    begin_primaryArtifact ()
    {
      return primaryArtifact_.begin ();
    }

    MonolithicImplementationDescription::primaryArtifact_iterator MonolithicImplementationDescription::
    end_primaryArtifact ()
    {
      return primaryArtifact_.end ();
    }

    MonolithicImplementationDescription::primaryArtifact_const_iterator MonolithicImplementationDescription::
    begin_primaryArtifact () const
    {
      return primaryArtifact_.begin ();
    }

    MonolithicImplementationDescription::primaryArtifact_const_iterator MonolithicImplementationDescription::
    end_primaryArtifact () const
    {
      return primaryArtifact_.end ();
    }

    void MonolithicImplementationDescription::
    add_primaryArtifact (::CIAO::Config_Handlers::NamedImplementationArtifact const& e)
    {
      if (primaryArtifact_.capacity () < primaryArtifact_.size () + 1)
      {
        ::std::vector< ::CIAO::Config_Handlers::NamedImplementationArtifact > v;
        v.reserve (primaryArtifact_.size () + 1);

        while (primaryArtifact_.size ())
        {
          //@@ VC6
          ::CIAO::Config_Handlers::NamedImplementationArtifact& t = primaryArtifact_.back ();
          t.container (0);
          v.push_back (t);
          v.back ().container (this);
          primaryArtifact_.pop_back ();
        }

        primaryArtifact_.swap (v);
      }

      primaryArtifact_.push_back (e);
      primaryArtifact_.back ().container (this);
    }

    // MonolithicImplementationDescription
    // 
    bool MonolithicImplementationDescription::
    deployRequirement_p () const
    {
      return deployRequirement_.get () != 0;
    }

    ::CIAO::Config_Handlers::ImplementationRequirement const& MonolithicImplementationDescription::
    deployRequirement () const
    {
      return *deployRequirement_;
    }

    ::CIAO::Config_Handlers::ImplementationRequirement& MonolithicImplementationDescription::
    deployRequirement ()
    {
      return *deployRequirement_;
    }

    void MonolithicImplementationDescription::
    deployRequirement (::CIAO::Config_Handlers::ImplementationRequirement const& e)
    {
      if (deployRequirement_.get ())
      {
        *deployRequirement_ = e;
      }

      else
      {
        deployRequirement_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ImplementationRequirement > (new ::CIAO::Config_Handlers::ImplementationRequirement (e));
        deployRequirement_->container (this);
      }
    }


    // ComponentImplementationDescription
    // 

    ComponentImplementationDescription::
    ComponentImplementationDescription ()
    :
    regulator__ ()
    {
    }

    ComponentImplementationDescription::
    ComponentImplementationDescription (::CIAO::Config_Handlers::ComponentImplementationDescription const& s)
    :
    label_ (s.label_.get () ? new ::XMLSchema::string< char > (*s.label_) : 0),
    UUID_ (s.UUID_.get () ? new ::XMLSchema::string< char > (*s.UUID_) : 0),
    implements_ (s.implements_.get () ? new ::CIAO::Config_Handlers::ComponentInterfaceDescription (*s.implements_) : 0),
    assemblyImpl_ (s.assemblyImpl_.get () ? new ::CIAO::Config_Handlers::ComponentAssemblyDescription (*s.assemblyImpl_) : 0),
    monolithicImpl_ (s.monolithicImpl_.get () ? new ::CIAO::Config_Handlers::MonolithicImplementationDescription (*s.monolithicImpl_) : 0),
    configProperty_ (s.configProperty_.get () ? new ::CIAO::Config_Handlers::Property (*s.configProperty_) : 0),
    capability_ (s.capability_.get () ? new ::CIAO::Config_Handlers::Capability (*s.capability_) : 0),
    dependsOn_ (s.dependsOn_.get () ? new ::CIAO::Config_Handlers::ImplementationDependency (*s.dependsOn_) : 0),
    infoProperty_ (s.infoProperty_.get () ? new ::CIAO::Config_Handlers::Property (*s.infoProperty_) : 0),
    contentLocation_ (s.contentLocation_.get () ? new ::XMLSchema::string< char > (*s.contentLocation_) : 0),
    regulator__ ()
    {
      if (label_.get ()) label_->container (this);
      if (UUID_.get ()) UUID_->container (this);
      if (implements_.get ()) implements_->container (this);
      if (assemblyImpl_.get ()) assemblyImpl_->container (this);
      if (monolithicImpl_.get ()) monolithicImpl_->container (this);
      if (configProperty_.get ()) configProperty_->container (this);
      if (capability_.get ()) capability_->container (this);
      if (dependsOn_.get ()) dependsOn_->container (this);
      if (infoProperty_.get ()) infoProperty_->container (this);
      if (contentLocation_.get ()) contentLocation_->container (this);
    }

    ::CIAO::Config_Handlers::ComponentImplementationDescription& ComponentImplementationDescription::
    operator= (::CIAO::Config_Handlers::ComponentImplementationDescription const& s)
    {
      if (s.label_.get ()) label (*(s.label_));
      else label_ = ::std::auto_ptr< ::XMLSchema::string< char > > (0);

      if (s.UUID_.get ()) UUID (*(s.UUID_));
      else UUID_ = ::std::auto_ptr< ::XMLSchema::string< char > > (0);

      if (s.implements_.get ()) implements (*(s.implements_));
      else implements_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentInterfaceDescription > (0);

      if (s.assemblyImpl_.get ()) assemblyImpl (*(s.assemblyImpl_));
      else assemblyImpl_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentAssemblyDescription > (0);

      if (s.monolithicImpl_.get ()) monolithicImpl (*(s.monolithicImpl_));
      else monolithicImpl_ = ::std::auto_ptr< ::CIAO::Config_Handlers::MonolithicImplementationDescription > (0);

      if (s.configProperty_.get ()) configProperty (*(s.configProperty_));
      else configProperty_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (0);

      if (s.capability_.get ()) capability (*(s.capability_));
      else capability_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Capability > (0);

      if (s.dependsOn_.get ()) dependsOn (*(s.dependsOn_));
      else dependsOn_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ImplementationDependency > (0);

      if (s.infoProperty_.get ()) infoProperty (*(s.infoProperty_));
      else infoProperty_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (0);

      if (s.contentLocation_.get ()) contentLocation (*(s.contentLocation_));
      else contentLocation_ = ::std::auto_ptr< ::XMLSchema::string< char > > (0);

      return *this;
    }


    // ComponentImplementationDescription
    // 
    bool ComponentImplementationDescription::
    label_p () const
    {
      return label_.get () != 0;
    }

    ::XMLSchema::string< char > const& ComponentImplementationDescription::
    label () const
    {
      return *label_;
    }

    ::XMLSchema::string< char >& ComponentImplementationDescription::
    label ()
    {
      return *label_;
    }

    void ComponentImplementationDescription::
    label (::XMLSchema::string< char > const& e)
    {
      if (label_.get ())
      {
        *label_ = e;
      }

      else
      {
        label_ = ::std::auto_ptr< ::XMLSchema::string< char > > (new ::XMLSchema::string< char > (e));
        label_->container (this);
      }
    }

    // ComponentImplementationDescription
    // 
    bool ComponentImplementationDescription::
    UUID_p () const
    {
      return UUID_.get () != 0;
    }

    ::XMLSchema::string< char > const& ComponentImplementationDescription::
    UUID () const
    {
      return *UUID_;
    }

    ::XMLSchema::string< char >& ComponentImplementationDescription::
    UUID ()
    {
      return *UUID_;
    }

    void ComponentImplementationDescription::
    UUID (::XMLSchema::string< char > const& e)
    {
      if (UUID_.get ())
      {
        *UUID_ = e;
      }

      else
      {
        UUID_ = ::std::auto_ptr< ::XMLSchema::string< char > > (new ::XMLSchema::string< char > (e));
        UUID_->container (this);
      }
    }

    // ComponentImplementationDescription
    // 
    bool ComponentImplementationDescription::
    implements_p () const
    {
      return implements_.get () != 0;
    }

    ::CIAO::Config_Handlers::ComponentInterfaceDescription const& ComponentImplementationDescription::
    implements () const
    {
      return *implements_;
    }

    ::CIAO::Config_Handlers::ComponentInterfaceDescription& ComponentImplementationDescription::
    implements ()
    {
      return *implements_;
    }

    void ComponentImplementationDescription::
    implements (::CIAO::Config_Handlers::ComponentInterfaceDescription const& e)
    {
      if (implements_.get ())
      {
        *implements_ = e;
      }

      else
      {
        implements_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentInterfaceDescription > (new ::CIAO::Config_Handlers::ComponentInterfaceDescription (e));
        implements_->container (this);
      }
    }

    // ComponentImplementationDescription
    // 
    bool ComponentImplementationDescription::
    assemblyImpl_p () const
    {
      return assemblyImpl_.get () != 0;
    }

    ::CIAO::Config_Handlers::ComponentAssemblyDescription const& ComponentImplementationDescription::
    assemblyImpl () const
    {
      return *assemblyImpl_;
    }

    ::CIAO::Config_Handlers::ComponentAssemblyDescription& ComponentImplementationDescription::
    assemblyImpl ()
    {
      return *assemblyImpl_;
    }

    void ComponentImplementationDescription::
    assemblyImpl (::CIAO::Config_Handlers::ComponentAssemblyDescription const& e)
    {
      if (assemblyImpl_.get ())
      {
        *assemblyImpl_ = e;
      }

      else
      {
        assemblyImpl_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentAssemblyDescription > (new ::CIAO::Config_Handlers::ComponentAssemblyDescription (e));
        assemblyImpl_->container (this);
      }
    }

    // ComponentImplementationDescription
    // 
    bool ComponentImplementationDescription::
    monolithicImpl_p () const
    {
      return monolithicImpl_.get () != 0;
    }

    ::CIAO::Config_Handlers::MonolithicImplementationDescription const& ComponentImplementationDescription::
    monolithicImpl () const
    {
      return *monolithicImpl_;
    }

    ::CIAO::Config_Handlers::MonolithicImplementationDescription& ComponentImplementationDescription::
    monolithicImpl ()
    {
      return *monolithicImpl_;
    }

    void ComponentImplementationDescription::
    monolithicImpl (::CIAO::Config_Handlers::MonolithicImplementationDescription const& e)
    {
      if (monolithicImpl_.get ())
      {
        *monolithicImpl_ = e;
      }

      else
      {
        monolithicImpl_ = ::std::auto_ptr< ::CIAO::Config_Handlers::MonolithicImplementationDescription > (new ::CIAO::Config_Handlers::MonolithicImplementationDescription (e));
        monolithicImpl_->container (this);
      }
    }

    // ComponentImplementationDescription
    // 
    bool ComponentImplementationDescription::
    configProperty_p () const
    {
      return configProperty_.get () != 0;
    }

    ::CIAO::Config_Handlers::Property const& ComponentImplementationDescription::
    configProperty () const
    {
      return *configProperty_;
    }

    ::CIAO::Config_Handlers::Property& ComponentImplementationDescription::
    configProperty ()
    {
      return *configProperty_;
    }

    void ComponentImplementationDescription::
    configProperty (::CIAO::Config_Handlers::Property const& e)
    {
      if (configProperty_.get ())
      {
        *configProperty_ = e;
      }

      else
      {
        configProperty_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (new ::CIAO::Config_Handlers::Property (e));
        configProperty_->container (this);
      }
    }

    // ComponentImplementationDescription
    // 
    bool ComponentImplementationDescription::
    capability_p () const
    {
      return capability_.get () != 0;
    }

    ::CIAO::Config_Handlers::Capability const& ComponentImplementationDescription::
    capability () const
    {
      return *capability_;
    }

    ::CIAO::Config_Handlers::Capability& ComponentImplementationDescription::
    capability ()
    {
      return *capability_;
    }

    void ComponentImplementationDescription::
    capability (::CIAO::Config_Handlers::Capability const& e)
    {
      if (capability_.get ())
      {
        *capability_ = e;
      }

      else
      {
        capability_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Capability > (new ::CIAO::Config_Handlers::Capability (e));
        capability_->container (this);
      }
    }

    // ComponentImplementationDescription
    // 
    bool ComponentImplementationDescription::
    dependsOn_p () const
    {
      return dependsOn_.get () != 0;
    }

    ::CIAO::Config_Handlers::ImplementationDependency const& ComponentImplementationDescription::
    dependsOn () const
    {
      return *dependsOn_;
    }

    ::CIAO::Config_Handlers::ImplementationDependency& ComponentImplementationDescription::
    dependsOn ()
    {
      return *dependsOn_;
    }

    void ComponentImplementationDescription::
    dependsOn (::CIAO::Config_Handlers::ImplementationDependency const& e)
    {
      if (dependsOn_.get ())
      {
        *dependsOn_ = e;
      }

      else
      {
        dependsOn_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ImplementationDependency > (new ::CIAO::Config_Handlers::ImplementationDependency (e));
        dependsOn_->container (this);
      }
    }

    // ComponentImplementationDescription
    // 
    bool ComponentImplementationDescription::
    infoProperty_p () const
    {
      return infoProperty_.get () != 0;
    }

    ::CIAO::Config_Handlers::Property const& ComponentImplementationDescription::
    infoProperty () const
    {
      return *infoProperty_;
    }

    ::CIAO::Config_Handlers::Property& ComponentImplementationDescription::
    infoProperty ()
    {
      return *infoProperty_;
    }

    void ComponentImplementationDescription::
    infoProperty (::CIAO::Config_Handlers::Property const& e)
    {
      if (infoProperty_.get ())
      {
        *infoProperty_ = e;
      }

      else
      {
        infoProperty_ = ::std::auto_ptr< ::CIAO::Config_Handlers::Property > (new ::CIAO::Config_Handlers::Property (e));
        infoProperty_->container (this);
      }
    }

    // ComponentImplementationDescription
    // 
    bool ComponentImplementationDescription::
    contentLocation_p () const
    {
      return contentLocation_.get () != 0;
    }

    ::XMLSchema::string< char > const& ComponentImplementationDescription::
    contentLocation () const
    {
      return *contentLocation_;
    }

    ::XMLSchema::string< char >& ComponentImplementationDescription::
    contentLocation ()
    {
      return *contentLocation_;
    }

    void ComponentImplementationDescription::
    contentLocation (::XMLSchema::string< char > const& e)
    {
      if (contentLocation_.get ())
      {
        *contentLocation_ = e;
      }

      else
      {
        contentLocation_ = ::std::auto_ptr< ::XMLSchema::string< char > > (new ::XMLSchema::string< char > (e));
        contentLocation_->container (this);
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    // SubcomponentInstantiationDescription
    //

    SubcomponentInstantiationDescription::
    SubcomponentInstantiationDescription (::XSCRT::XML::Element< char > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< char > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< char > e (p.next_element ());
        ::std::basic_string< char > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< char > > (new ::XMLSchema::string< char > (e));
          name_->container (this);
        }

        else if (n == "package")
        {
          package_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentPackageDescription > (new ::CIAO::Config_Handlers::ComponentPackageDescription (e));
          package_->container (this);
        }

        else if (n == "configProperty")
        {
          ::CIAO::Config_Handlers::Property t (e);
          configProperty (t);
        }

        else if (n == "selectRequirement")
        {
          ::CIAO::Config_Handlers::Requirement t (e);
          selectRequirement (t);
        }

        else if (n == "reference")
        {
          ::CIAO::Config_Handlers::ComponentPackageReference t (e);
          reference (t);
        }

        else 
        {
        }
      }

      while (p.more_attributes ())
      {
        ::XSCRT::XML::Attribute< char > a (p.next_attribute ());
        ::std::basic_string< char > n (::XSCRT::XML::uq_name (a.name ()));
        if (n == "id")
        {
          ::XMLSchema::ID< char > t (a);
          id (t);
        }

        else 
        {
        }
      }
    }

    // SubcomponentPropertyReference
    //

    SubcomponentPropertyReference::
    SubcomponentPropertyReference (::XSCRT::XML::Element< char > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< char > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< char > e (p.next_element ());
        ::std::basic_string< char > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "propertyName")
        {
          propertyName_ = ::std::auto_ptr< ::XMLSchema::string< char > > (new ::XMLSchema::string< char > (e));
          propertyName_->container (this);
        }

        else if (n == "instance")
        {
          instance_ = ::std::auto_ptr< ::CIAO::Config_Handlers::SubcomponentInstantiationDescription > (new ::CIAO::Config_Handlers::SubcomponentInstantiationDescription (e));
          instance_->container (this);
        }

        else 
        {
        }
      }
    }

    // AssemblyPropertyMapping
    //

    AssemblyPropertyMapping::
    AssemblyPropertyMapping (::XSCRT::XML::Element< char > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< char > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< char > e (p.next_element ());
        ::std::basic_string< char > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "name")
        {
          name_ = ::std::auto_ptr< ::XMLSchema::string< char > > (new ::XMLSchema::string< char > (e));
          name_->container (this);
        }

        else if (n == "externalName")
        {
          externalName_ = ::std::auto_ptr< ::XMLSchema::string< char > > (new ::XMLSchema::string< char > (e));
          externalName_->container (this);
        }

        else if (n == "delegatesTo")
        {
          delegatesTo_ = ::std::auto_ptr< ::CIAO::Config_Handlers::SubcomponentPropertyReference > (new ::CIAO::Config_Handlers::SubcomponentPropertyReference (e));
          delegatesTo_->container (this);
        }

        else 
        {
        }
      }
    }

    // ComponentAssemblyDescription
    //

    ComponentAssemblyDescription::
    ComponentAssemblyDescription (::XSCRT::XML::Element< char > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< char > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< char > e (p.next_element ());
        ::std::basic_string< char > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "instance")
        {
          ::CIAO::Config_Handlers::SubcomponentInstantiationDescription t (e);
          add_instance (t);
        }

        else if (n == "connection")
        {
          ::CIAO::Config_Handlers::AssemblyConnectionDescription t (e);
          add_connection (t);
        }

        else if (n == "externalProperty")
        {
          ::CIAO::Config_Handlers::AssemblyPropertyMapping t (e);
          externalProperty (t);
        }

        else 
        {
        }
      }
    }

    // MonolithicImplementationDescription
    //

    MonolithicImplementationDescription::
    MonolithicImplementationDescription (::XSCRT::XML::Element< char > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< char > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< char > e (p.next_element ());
        ::std::basic_string< char > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "execParameter")
        {
          ::CIAO::Config_Handlers::Property t (e);
          execParameter (t);
        }

        else if (n == "primaryArtifact")
        {
          ::CIAO::Config_Handlers::NamedImplementationArtifact t (e);
          add_primaryArtifact (t);
        }

        else if (n == "deployRequirement")
        {
          ::CIAO::Config_Handlers::ImplementationRequirement t (e);
          deployRequirement (t);
        }

        else 
        {
        }
      }
    }

    // ComponentImplementationDescription
    //

    ComponentImplementationDescription::
    ComponentImplementationDescription (::XSCRT::XML::Element< char > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< char > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< char > e (p.next_element ());
        ::std::basic_string< char > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "label")
        {
          ::XMLSchema::string< char > t (e);
          label (t);
        }

        else if (n == "UUID")
        {
          ::XMLSchema::string< char > t (e);
          UUID (t);
        }

        else if (n == "implements")
        {
          ::CIAO::Config_Handlers::ComponentInterfaceDescription t (e);
          implements (t);
        }

        else if (n == "assemblyImpl")
        {
          ::CIAO::Config_Handlers::ComponentAssemblyDescription t (e);
          assemblyImpl (t);
        }

        else if (n == "monolithicImpl")
        {
          ::CIAO::Config_Handlers::MonolithicImplementationDescription t (e);
          monolithicImpl (t);
        }

        else if (n == "configProperty")
        {
          ::CIAO::Config_Handlers::Property t (e);
          configProperty (t);
        }

        else if (n == "capability")
        {
          ::CIAO::Config_Handlers::Capability t (e);
          capability (t);
        }

        else if (n == "dependsOn")
        {
          ::CIAO::Config_Handlers::ImplementationDependency t (e);
          dependsOn (t);
        }

        else if (n == "infoProperty")
        {
          ::CIAO::Config_Handlers::Property t (e);
          infoProperty (t);
        }

        else if (n == "contentLocation")
        {
          ::XMLSchema::string< char > t (e);
          contentLocation (t);
        }

        else 
        {
        }
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

