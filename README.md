# CTGU_Software_Engineering_Work
😘三峡大学2021秋季学期软件工程作业
> 使用C++通过规范的封装结合自写的词汇解析算法快速完成实验需求。
底层均为个人实现未调用任何第三方库文件。一天时间完成功能实现。仓库暂停更新。 

> 仓库管理员: 【[CTGU_LLZ](https://www.yuque.com/404name/blog/cbt8cl)】

> 仓库在线预览：【[点我](https://github1s.com/404name/CTGU_Software_Engineering_Work)】

> 作业发布地址：【[点我](https://star.jmhui.com.cn/p1/366.html)】

![效果展示](https://gitee.com/N404name/gitee-img/raw/master/myImg/dwadwadwadaadx.png)

| 文件夹 | 	内容 | 	时间 | 
|  ----  | ----  |----  |
| EP1 编程基本练习	 | 三个基本编程实验 | 	2021/9/13 | 
| EP1 单词统计器[小项目] | 	一个综合的单词统计小程序 | 	2021/9/13 | 
| 【🎈待添加】 | 	【🎈待添加】	 | 【🎈待添加】 | 

# 使用方法
> 在当前文件下开启cmd窗口，**输入wf查看提示**
> 
> 默认数据测试为：**wf -f one.txt -n 10 -s save.txt -x -f stopwords_en.txt**
> 
> git仓库不支持100mb文件|因此测试文件未上传
> 
文件测试后续更新
# 测试数据集
> 600部小说（github仓库大文件未能上传仅展示测试数据）

> 测试指令：**wf -d ./600篇英文小说 -s res.txt -x -f stopwords_en.txt -n 100 -p 3** 

输出长度为3的词汇并且存在res里面
```
....省略
正在加载./600篇英文小说\Where the Blue Begins(蓝调从何而起)_Password_Removed.txt
正在加载./600篇英文小说\White Fang(白牙)_Password_Removed.txt
正在加载./600篇英文小说\Who Was Who_5000 B_Password_Removed.txt
正在加载./600篇英文小说\Why Go To College(为什么上大学)_Password_Removed.txt
正在加载./600篇英文小说\Wives and Daughters(妻子与女儿)_Password_Removed.txt
正在加载./600篇英文小说\Worldly Ways and Byways(世俗之路)_Password_Removed.txt
正在加载./600篇英文小说\Wreck of the Golden Mary(金玛丽的遗骸)_Password_Removed.txt
正在加载./600篇英文小说\Wyoming(怀俄明)_Password_Removed.txt
正在加载./600篇英文小说\Yankee Gypsies(美国吉普赛人)_Password_Removed.txt
正在加载./600篇英文小说\[19th Century Actor] AUTOBIOGRAPHY(十九世纪男演员自传)_Password_Removed.txt
No1:charles dickens elecbook 6398
No2:dickens elecbook classics 6398
No3:one of the 6216
No4:out of the 5473
No5:it was a 4395
No6:there was a 4380
No7:that he was 3103
No8:that he had 2986
No9:i do not 2831
No10:that it was 2789
No11:there was no 2736
No12:it is a 2703
No13:it is not 2591
No14:it would be 2564
No15:he had been 2563
No16:he did not 2536
....省略
```

# 更新 && 开发进度
> 【===============>】**进度100**
## 9.14 17点
+ 友好的界面提醒[仿java -help提示效果]
+ 命令检测，自动排序
+ 短语检索[使用长度为n的队列实现]
+ 采用算法对文件读取进行优化


<details>

<summary>【点我】查看更多</summary>

+ 友好的界面提醒[仿java -help提示效果]
+ 命令检测，自动排序
+ 短语检索[使用长度为n的队列实现]
```
argument[0] is: C:\Users\404name\Desktop\CTGU_Software_Engineering_Work\EP1 单词统计器[小项目]\wf.exe
[用法]：wf [-options] [args]
[例子]：wf -f one.txt -n 10 -s save.txt
[解释]：读取one，输出前10高频词汇，且存入save,选项不分前后，系统自带检测排序功能
其中选项包括
    -------------- 【可选】载入转换文件
    -x -f [文件]   读取停词表文件,过滤单词
    -v [文件]      读取转换表文件,转换原型
    -s [文件]      存储结果至文件内
    -------------- 【可选】输出设定
    -n [单词数量]  结果取频率最高前N个(默认全部)
    -p [短语长度]  设定输出短语长度(默认为单词长度为1)
    -------------- 【必选】载入文本文件
    -f [文件]      加载文本文件
    -d [文件夹]    读取当前文件夹下所有文本文件
    -d -s [文件夹] 递归读取当前文件夹下所有文本文件
```
## 9/13 22点~
+ 更快读取
+ 优化框架，功能分离
+ 整体封装

## 9/13 20点

- [x] 文件递归读取
- [ ] 短语分析
- [x] 更精确的单词分析
- [ ] UI界面
- [ ] 实现args命令调用任务

```
argument[0] is: C:\Users\404name\Desktop\CTGU_Software_Enginee                ring_Work\EP1 单词统计器[小项目]\wf.exe
正在加载C:\Users\404name\Desktop\CTGU_Software_Engineering_Wor                k\EP1 单词统计器[小项目]\one.txt
正在加载C:\Users\404name\Desktop\CTGU_Software_Engineering_Wor                k\EP1 单词统计器[小项目]\save.txt
正在加载C:\Users\404name\Desktop\CTGU_Software_Engineering_Wor                k\EP1 单词统计器[小项目]\stopwords.txt
正在加载C:\Users\404name\Desktop\CTGU_Software_Engineering_Wor                k\EP1 单词统计器[小项目]\stopwords_en.txt
正在加载C:\Users\404name\Desktop\CTGU_Software_Engineering_Wor                k\EP1 单词统计器[小项目]\完整测试集.txt
正在加载C:\Users\404name\Desktop\CTGU_Software_Engineering_Work\E             P1 编程基本练习\test\新建 文本文档.txt
No1:time 39622
No2:day 27311
No3:life 23737
No4:hand 20317
No5:eyes 20236
No6:house 19053
No7:night 17921
No8:sir 17754
No9:head 16925
No10:love 16824
请按任意键继续. . .

```
## 9/13 18点

- [x] 框架搭建完成
- [x] 封装[文件读取类][WF控制类]
- [x] 实现本地读取生成热词 top n
- [x] 实现读取stopword对热词进行过滤

后续任务

- [ ] 文件递归读取
- [ ] 短语分析
- [ ] 更精确的单词分析
- [ ] UI界面
- [ ] 实现args命令调用任务



</details>




# 实现功能

## 1. 命令检测+纠正排序
**[input 正确的输入]**
> \>wf -f one.txt -n 10 -s save.txt

输出命令解析
自动排序
执行对于命令
> [解析]：你的操作如下
       存储文件至->save.txt
     显示单词数量->10
     加载文本资源->one.txt
[确认]：Y/N
No1:the 3
No2:and 2
No3:face 2
No4:people 2
No5:are 1
No6:bleak 1
No7:blood 1
No8:chinese 1

**[input 错误的输入]**
> \>wf -f one.txt -n 10 -s save.txt dawdawd

输出错误内容并且提示用法
> 【错误】找不到参数dawdawd
[用法]：wf [-options] [args]
[例子]：wf -f one.txt -n 10 -s save.txt


## 2. 单词解析
> 原理：
> 1. 遍历检索英文单词
> 2. 有单引号当且仅当左右都是英文则算单词
场景:[复杂的对话单引号]和[we'll can't形式]

[input] 鲁迅名言
```
Lu Xun said 'learning medicine couldn't save the Chinese people'
What kind of sad and happy people are real warriors who dare to face the bleak life and face the dripping blood?
```
[out] 
```
No1:the 3
No2:and 2
No3:face 2
No4:people 2
No5:are 1
No6:bleak 1
No7:blood 1
No8:chinese 1
```
## 3. 短语解析
> 定义face the是短语。face逗号the不是短语     
> 上述单词其实就是长度为1的短语
> 实现原理：维护n长度的队列，
> 1. 解析到单词加入 2. 队列长度符合则导出一次并且弹出头 3. 遇到非单词清空队列 

[input]
```
Lu Xun said 'learning medicine couldn't save the Chinese people'
What kind of sad and happy people are real warriors who dare to face the bleak life and face the dripping blood?
```
[out] 完美~
```
No1:face the 2
No2:and face 1
No3:and happy 1
No4:are real 1
No5:bleak life 1
No6:chinese people 1
No7:couldn't save 1
No8:dare to 1
```

# 设计布局
## WordFrequence封装主功能
| 成员对象                                 | 功能                                      | 备注                   |
| ---------------------------------------- | ----------------------------------------- | ---------------------- |
| static void loadFile(char * path)        | 调用FileUtil解析文件返回单词表            | 【仿单例模式】静态方法 |
| static void loadPath(char * path)        | 解析地址下所有txt，再调用loadFile读取所有 | 【仿单例模式】静态方法 |
| static void loadStopWords(char * path)   | 读取停词表                                | 【仿单例模式】静态方法 |
| static void loadchangeWords(char * path) | 读取动词-原型 表                          | 【仿单例模式】静态方法 |
| static void print()                      | 打印top单词                               | 【仿单例模式】静态方法 |
| static void save(char * inPath)          | 保存再本地                                | 【仿单例模式】静态方法 |



## FileUtil处理所有文件相关
| 成员对象                                 | 功能                                      | 备注                   |
| ---------------------------------------- | ----------------------------------------- | ---------------------- |
| static void read(char* file_path,vector<string> &vec,int lenth)      | 读取文件并且寻找长度为N的词汇存vec            | 【仿单例模式】静态方法 |
| static void getFileNames(string path,vector<string>& files)      | 解析文件夹内所有文件并且文件存files内方便再遍历去读取 | 【仿单例模式】静态方法 |



## Command封装命令相关功能
命令提示|检查|调整
| 成员对象                                 | 功能                                      | 备注                   |
| ---------------------------------------- | ----------------------------------------- | ---------------------- |
|static bool praseCmd(int argc,char *argv[]) | 获取cmd里面的命令并且统一处理封装并且检测语法      | 【仿单例模式】静态方法 |
|static void confirmCommandList()     |确认命令列表 | 【仿单例模式】静态方法 |
| static void loadStopWords(char * path)   | 读取停词表                                | 【仿单例模式】静态方法 |
|static void showHelp() | 当语法错误或者无输入时调用显示使用手册   | 【仿单例模式】静态方法 |
|static void addCommand(string key,Command * command)              | 添加指令到指令集        | 【仿单例模式】静态方法 |
| void print(){    | 指令输出自己的内容           | 对象调用 |
| void printTip(){    | 指令输出自己的提示           | 对象调用 |
