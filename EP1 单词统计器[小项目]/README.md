# 进度

## 9.14 13点
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


