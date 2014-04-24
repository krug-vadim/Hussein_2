#ifndef LOG_H
#define LOG_H

class Log
{
	public:
		Log();

		enum
		{
			ErrorEvent   = 0x0001U,
			InfoEvent    = 0x0002U,
			WarningEvent = 0x0004U,

			SystemEvent  = 0x0010U,
			UserEvent    = 0x0020U,
			DebugEvent   = 0x0040U
		}
		LogEvent;
};


#endif // LOG_H
