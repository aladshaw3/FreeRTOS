#include "port_template_wrapper.h"
#include "port_template.h"

void *createMyPort()
{
  return new Port<double>();
}

void deleteMyPort(void *obj)
{
  delete static_cast<Port<double> *>(obj);
}

void initializeMyPort(void *obj, double init)
{
  (static_cast<Port<double> *>(obj))->initializePort(init);
}

void setMyPortTime(void *obj, double time)
{
  (static_cast<Port<double> *>(obj))->setState(time);
}

double getMyPortTime(void *obj)
{
  return (static_cast<Port<double> *>(obj))->getState();
}
