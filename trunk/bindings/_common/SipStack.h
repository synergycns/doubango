/*
* Copyright (C) 2009-2010 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou(at)doubango.org>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/
#ifndef TINYWRAP_SIPSTACK_H
#define TINYWRAP_SIPSTACK_H

#include "SipCallback.h"
#include "SafeObject.h"

#include "tinysip.h"

class DDebugCallback;

class SipStack: public SafeObject
{
public: /* ctor() and dtor() */
	SipStack(SipCallback* callback, const char* realm_uri, const char* impi_uri, const char* impu_uri);
    ~SipStack();

public: /* API functions */
	bool start();
	bool setDebugCallback(DDebugCallback* callback);
	bool setRealm(const char* realm_uri);
	bool setIMPI(const char* impi);
	bool setIMPU(const char* impu_uri);
	bool setPassword(const char* password);
	bool setProxyCSCF(const char* fqdn, unsigned port, const char* transport, const char* ipversion);
	bool setLocalIP(const char* ip);
	bool setLocalPort(unsigned port);
	bool setEarlyIMS(bool enabled);
	bool addHeader(const char* name, const char* value);
	bool removeHeader(const char* name);
	bool addDnsServer(const char* ip);
	bool setAoR(const char* ip, int port);

	bool isValid();
	bool stop();

public: /* Public helper function */
#if !defined(SWIG)
	tsip_stack_handle_t* getHandle()const;
	SipCallback* getCallback()const;
	DDebugCallback* getDebugCallback() const;
#endif

private:
	SipCallback* callback;
	DDebugCallback* debugCallback;
	tsip_stack_handle_t *handle;

	static unsigned count;
};

#endif /* TINYWRAP_SIPSTACK_H */