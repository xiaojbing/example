#include "examplesApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
examplesApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

examplesApp::examplesApp(InputParameters parameters) : MooseApp(parameters)
{
  examplesApp::registerAll(_factory, _action_factory, _syntax);
}

examplesApp::~examplesApp() {}

void
examplesApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"examplesApp"});
  Registry::registerActionsTo(af, {"examplesApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
examplesApp::registerApps()
{
  registerApp(examplesApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
examplesApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  examplesApp::registerAll(f, af, s);
}
extern "C" void
examplesApp__registerApps()
{
  examplesApp::registerApps();
}
