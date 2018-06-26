/* 说明：用法和mutex一模一样，这里就不罗列demo了
 * 注意：1.自旋锁会占用CPU，让其处于忙等状态，同时，还会“阻塞中断”，这很有用，某些相当关键的代码，如果加上自旋锁，那么可以有效的屏蔽中断的干扰，不过这种场景在用户
 * 	 环境不常见，多出现在内核编程中
 * 	 2.lock和trylock返回0就表示加锁成功，否则失败
 *
 * */
