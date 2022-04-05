# Despatt

> Go 实现白话设计模式 28 讲

[English](README.md) | 简体中文

- [Despatt](#despatt)
  - [介绍](#介绍)
  - [内容](#内容)
    - [2.1 原创](#21-原创)
    - [2.2 标准](#22-标准)
  - [贡献](#贡献)
  - [许可证](#许可证)
  - [联系](#联系)

## 介绍

Despatt 主要参考 [《人人皆知设计模式：如何从日常生活中理解设计模式》](https://gitbook.cn/gitchat/column/5b26040ac81ac568fcf64ea3)，
其中介绍了：
- 19 种开发常用的设计模式，其余 4 种很少使用的设计模式
- 基本设计模式的推导，以及重要且通用的编程机制
- 来自 [罗伟富](https://github.com/luoweifu) 的设计原则、设计模式、项目重构的经验和看法

更重要的是，我建议你在阅读整个内容之前，根据你的语言，阅读一些特定的文章：
- Go
  - 简例模式
  - 工厂模式
  - 策略模式
  - 模块模式
  - 代理模式
  - 选项模式

欢迎为 Despatt 贡献不同编程语言的实现，例如 Java、C++、Rust、JavaScript 和 ...
- [x] Python(默认) - [luoweifu/PyDesignPattern](https://github.com/luoweifu/PyDesignPattern)
- [ ] Go - @Jacob953
- [ ] JavaScript - @Rick Lin

## 内容


如果你是 [设计模式](https://en.wikipedia.org/wiki/Design_Patterns) 的新手，我建议你按照 [原创](#21-原创) 的目录来阅读。
同样，你也可以按照GoF的 [标准](#22-standard) 方式找出你需要的东西。

### 2.1 原创

1. [观察者](global/01-observer/README.md)
2. [适配器](global/02-adapter/README.md)
3. [状态](global/03-state/README.md)
4. [单例](global/04-singleton/README.md)
5. [责任](global/05-responsibility/README.md)
6. [调解器](global/06-mediator/README.md)
7. [代理](global/07-proxy/README.md)
8. [装饰器](global/08-decorator/README.md)
9. [工厂](global/09-factory/README.md)
10. [迭代器](global/10-iterator/README.md)

### 2.2 标准

**创造型**

- [工厂](global/09-factory/README.md)
- [单例](global/04-singleton/README.md)

**结构性**

- [适配器](global/02-adapter/README.md)
- [装饰器](global/08-decorator/README.md)
- [代理](global/07-proxy/README.md)

**行为**

- [责任](global/05-responsibility/README.md)
- [迭代器](global/10-iterator/README.md)
- [调解器](global/06-mediator/README.md)
- [观察者](global/01-observer/README.md)
- [状态](global/03-state/README.md)

## 贡献

<p align="center"><b>请在直接 PR 之前提出您的 issue ！</b></p>

欢迎贡献，包括但不限于以下形式：

1. 翻译成另一种语言
2. 添加新的编程语言
3. 修正错别字或错误
4. 告诉我你的期望
5. ……

**注意**

如果您要添加新的编程语言，请遵守以下规则：

1. 确保您的问题已被阅读并获得批准。（在那之后，我会为你的贡献创建一个新的分支，例如 `dev-go`）
2. 新建一个和 `global` 同级的文件夹，用新的语言命名文件夹，例如 `go`
3. 将文件夹结构从 `global` 复制到新文件夹，例如 `go` 
4. 将您的提交推送到特定分支，例如 `dev-go`
5. 合并到分支 `develop` 中，而不是 `main` 分支

## 许可证

Despatt 遵循 [GPL-3.0 许可证](LICENSE)

## 联系

您可以通过 [jacob953@csu.edu.cn](mailto:jacob953@csu.edu.cn) 与我联系
