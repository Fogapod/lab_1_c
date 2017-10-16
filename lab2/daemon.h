#ifndef DAEMON_H_
#define DAEMON_H_


#ifndef __ANDROID_API__
#define PID_FILE "/usr/var/run/myhttpserver.pid"

#else /* Running in Termux */
#define PID_FILE "/data/data/com.termux/files/usr/var/run/myhttpserver.pid"

#endif

void daemonize(void);

#endif /* DAEMON_H_ */
