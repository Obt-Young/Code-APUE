//描述：1.是否排队取决于具体的系统实现(因此最好先在当前系统上测试下)；
//	2.信号的阻塞队列是由上限的,ulimit -i可以查看pending信号的最大长度，从字面上理解，pending队列应该就是信号的队列，因为不能被递送就
//	  以为这排队
//	3.可使用sigqueue函数发送信号时，信号时排队的，同时这个函数还可以携带数据给信号处理函数，这一点用处很大
//      4.后期又出现了实时信号集，面向应用层的，和SIGUSR1、SIGUSR2地位一样，只不过这些信号的默认动作时终止进程(SIGRTMIN~SIGRTMAX).
//
