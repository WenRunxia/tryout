#include "tryoutApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
tryoutApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

tryoutApp::tryoutApp(InputParameters parameters) : MooseApp(parameters)
{
  tryoutApp::registerAll(_factory, _action_factory, _syntax);
}

tryoutApp::~tryoutApp() {}

void
tryoutApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"tryoutApp"});
  Registry::registerActionsTo(af, {"tryoutApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
tryoutApp::registerApps()
{
  registerApp(tryoutApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
tryoutApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  tryoutApp::registerAll(f, af, s);
}
extern "C" void
tryoutApp__registerApps()
{
  tryoutApp::registerApps();
}
