# Despatt

> Vernacular Design Patterns 28 Lectures implement by Go

English | [简体中文](README-zh.md)

- [Despatt](#despatt)
  - [1 Introduction](#1-introduction)
  - [2 Content](#2-content)
    - [2.1 Original](#21-original)
    - [2.2 Standard](#22-standard)
  - [3 Contribution](#3-contribution)
  - [4 License](#4-license)
  - [5 Contact](#5-contact)

## 1 Introduction

Despatt mainly refer to [Everybody Know Design Patterns : How to comprehend Design Patterns from daily life](https://gitbook.cn/gitchat/column/5b26040ac81ac568fcf64ea3), 
which introduces: 
- 19 commonly used design patterns for development and other 4 seldomly used design patterns in the remaining
- Derivation of basic design patterns, as well as important and common programming mechanism
- Experience and opinions on design principles, design patterns, and project reconstruction from [Weifu Luo](https://github.com/luoweifu)

More importantly, I recommend that you read some specific articles, depending on your language, before you read the entire content.
- Go
  - Singleton mode
  - Factory mode
  - Strategy mode
  - Module mode
  - Proxy mode
  - Option mode

Welcome to contribute Despatt with implements of different programming languages, such as Java, C++, Rust, and ...
- [x] Python(default) - [luoweifu/PyDesignPattern](https://github.com/luoweifu/PyDesignPattern)
- [ ] Go - @Jacob953
- [ ] JavaScript - @Rick Lin

## 2 Content

If you are new to the [Design Patterns](https://en.wikipedia.org/wiki/Design_Patterns), I suggest you follow the [Original](#21-original) table of contents. 
As well, you can just figure out what you need following GoF's [Standard](#22-standard) way.

### 2.1 Original

1. [Observer](global/01-observer/README.md)
2. [Adapter](global/02-adapter/README.md)
3. [State](global/03-state/README.md)
4. [Singleton](global/04-singleton/README.md)
5. [Responsibility](global/05-responsibility/README.md)
6. [Mediator](global/06-mediator/README.md)
7. [Proxy](global/07-proxy/README.md)
8. [Decorator](global/08-decorator/README.md)
9. [Factory](global/09-factory/README.md)
10. [Iterator](global/10-iterator/README.md)

### 2.2 Standard

**Creational**

- [Factory](global/09-factory/README.md)
- [Singleton](global/04-singleton/README.md)

**Structural**

- [Adapter](global/02-adapter/README.md)
- [Decorator](global/08-decorator/README.md)
- [Proxy](global/07-proxy/README.md)

**Behavioral**

- [Responsibility](global/05-responsibility/README.md)
- [Iterator](global/10-iterator/README.md)
- [Mediator](global/06-mediator/README.md)
- [Observer](global/01-observer/README.md)
- [State](global/03-state/README.md)

## 3 Contribution

<p align="center"><b>Please make your issue before pulling requests directly!</b></p>

Contributions including but not limited to the following forms are welcome.
1. Translate to a different language
2. Add a new programming language
3. Fix typos or mistakes
4. Tell me your expectations
5. ......

**Attention**

If you're going to add a new programming language, follow the rules.
1. Make sure your issue has been read and approved. (After that, I'll create a new branch for your contribution, like `dev-go`)
2. Create a new folder at the same level with `global`, and name the folder with the new language, like `go`
3. Copy the struct of folders from `global` to your new folder, like `go`
4. Push your commits to specific branch, like `dev-go`
5. Merge into branch `develop`, rather than `main`

## 4 License

Despatt follows the [GPL-3.0 License](LICENSE)

## 5 Contact

You can contact me by jacob953@csu.edu.cn
