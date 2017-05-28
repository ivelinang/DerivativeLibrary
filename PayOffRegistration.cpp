#include "PayOffConstructible.h"

namespace
{
	PayOffHelper<PayOffCall> RegisterCall("call");
	PayOffHelper<PayOffPut> RegisterPut("put");
}

//the variables RegisterCall and RegisterPut are both global and invisible
//invisible because of namespace
//invisible because we just used them for registering payoffs, after that we do not need those variables
