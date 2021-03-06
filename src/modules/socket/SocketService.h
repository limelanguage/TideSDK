/**
 * Copyright (c) 2012 - 2014 TideSDK contributors
 * http://www.tidesdk.org
 * Refer to LICENSE for details of distribution and use.
 **/

#ifndef _SOCKET_SERVICE_H_
#define _SOCKET_SERVICE_H_

#include <tide/tide.h>

// TODO: This is poco UnWindows.h's curse.... to be removed with poco
#ifdef UNICODE
#define CreateEvent  CreateEventW
#else
#define CreateEvent  CreateEventA
#endif // !UNICODE

#include <string>
#include <deque>

#include <boost/asio.hpp>
#include <boost/asio/detail/mutex.hpp>

using boost::asio::ip::tcp;

#include <boost/bind.hpp>
#include <boost/thread.hpp>

namespace ti
{
	class SocketService
	{
	public:
		static void initialize();
		static void uninitialize();
		static boost::asio::io_service* getIOService()
		{
			return io_service.get();
		}

	private:
		static std::auto_ptr<boost::asio::io_service> io_service;
		static std::auto_ptr<boost::asio::io_service::work> io_idlework;
		static std::auto_ptr<boost::thread> io_thread;
	};
}
#endif
