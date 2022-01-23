//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "tryoutTestApp.h"
#include "tryoutApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
tryoutTestApp::validParams()
{
  InputParameters params = tryoutApp::validParams();
  return params;
}

tryoutTestApp::tryoutTestApp(InputParameters parameters) : MooseApp(parameters)
{
  tryoutTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

tryoutTestApp::~tryoutTestApp() {}

void
tryoutTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  tryoutApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"tryoutTestApp"});
    Registry::registerActionsTo(af, {"tryoutTestApp"});
  }
}

void
tryoutTestApp::registerApps()
{
  registerApp(tryoutApp);
  registerApp(tryoutTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
tryoutTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  tryoutTestApp::registerAll(f, af, s);
}
extern "C" void
tryoutTestApp__registerApps()
{
  tryoutTestApp::registerApps();
}
