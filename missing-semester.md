---
title: missing-semester
date: 2023-04-11 22:39:53
toc: true
tags:
category: 其他
comments:
mathjax: 
---
这门课程只是对各方面进行一个基础的了解，我所记大部分抄录原文，具体学习看原网站：[missing-semester]

### Topic 1: The Shell
#### What is the shell?
当我们用各种各样的电脑接口时，我们经常被从根本上限制了。为了充分利用计算机提供的工具，我们不得不走老路下降到文本界面：the Shell

几乎所有的平台都有一个shell，即使他们不同，在各个shell的核心，它们很大程度上相似：它们允许你去运行程序、接受输入、以半结构化的方式检查输出

在这节课，我们将会集中于Bourne Again Shell，即"bash"，它是众多shell中的一员，并且它的语法和其它shell很类似。如果我们想打开一个shell，我们需要一个终端

#### Using the shell
首先，你会看到一个提示，通常看来是这样
```c++
missing:~$
```
"missing"是当前工作目录，"~"是"home"的缩写，"$"指没有root权限。你能输入一个命令，将会被shell解释，例如：
```shell
missing:~$ date
Fri 10 Jan 2020 11:49:31 AM EST
```
在这里，我们执行"data"程序，可以打印当前的事件，我么也可以执行一个带参数的程序：
```shell
missing:~$ echo hello
hello
```
在这个例子中，我们告诉shell使用参数`hello`执行`echo`，`echo`程序可以简单的打印它的参数。shell通过空格分割来解析命令，之后运行运行第一个单词指示的程序，之后的单词作为参数来提供程序访问。如果你想提供一个包括空格或者其他特殊符号（e.g，a directory named "My Photos"）作为参数，你能用`'`或者`"`来包住

但是，shell怎么知道如何去找这个`date`或`echo`程序？shell就是一个变成环境，就像Python和Ruby语言一样，所以它有变量、条件、循环和函数，当用shell执行命令时，实际上是执行一小段shell解释的代码，如果shell被告知要执行一个找不到关键字的命令，它会查询一个名为`$PATH`的环境变量，这个变量列出了收到命令时应该搜索的程序的目录，例如：
```shell
missing:~$ echo $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
missing:~$ which echo
/bin/echo
missing:~$ /bin/echo $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
```
当我们运行`echo`命令，shell会知道它要执行`echo`命令，然后在`PATH`中以`:`为分隔符分离的目录列表中搜索该名称的文件，当它找到后，它会运行命令（假设这个文件可执行）。我们能使用`which`命令找出要执行的程序在哪个目录，我们也能通过给出要执行的文件的路径来绕过`$PATH`。

#### Navigating in the shell
shell上的路径是一个带分隔符的目录列表，在Linux和macOS上用`/`分割，在Windows上用`\ `分割。在Linux中，路径`/`是文件系统的根目录，所有的目录和文件都位于该路径下

用`ls`命令查看当前目录下的文件，示例：
```shell
missing:~$ ls -l /home
drwxr-xr-x 1 missing  users  4096 Jun 15  2019 missing
```
其中第一个字符`d`表示missing是一个目录，然后接下来九个字符，每三个构成一组，分别代表了文件所有者(missing)、用户组(users)、以及其他所有人所具有的权限，其中`-`表示该用户不具备相应的权限。

其中`rwx`分别是读、写、执行，可用`chmod +x <file>`来使文件可执行，或者用`chmod 777 <file>`赋予文件所有权限（三个权限的权值分别是`124`

除此之外，还需要掌握`mv`（用于重命名或移动文件）、`cp`（拷贝文件）、`mkdir`（新建文件夹）

#### Connecting programs
在shell中，程序有两个主要的“流”：输入流和输出流。当程序尝试读取信息时，它们会从输入流中进行读取，当程序打印信息时，它们会将信息输出到输出流中。通常，一个程序的输入输出流都是您的终端。也就是，您的键盘作为输入，显示器作为输出，当然可以重定向这些流。

最简单的重定向是`< file`和`> file`这两个命令，可以将程序的输入输出流分别重定向到文件，示例：
```shell
missing:~$ echo hello > hello.txt
missing:~$ cat hello.txt
hello
missing:~$ cat < hello.txt
hello
missing:~$ cat < hello.txt > hello2.txt
missing:~$ cat hello2.txt
hello
```
还可以用`>>`来向一个文件追加内容，使用管道，我们能更好的利用文件重定向。`|`操作符允许我们将一个程序的输出和另外一个程序的输入连接起来，示例：
```
missing:~$ ls -l / | tail -n1
drwxr-xr-x 1 root  root  4096 Jun 20  2019 var
missing:~$ curl --head --silent google.com | grep --ignore-case content-length | cut --delimiter=' ' -f2
219
```


参考：<https://missing.csail.mit.edu/2020/>