# CleanYourScreen 清理屏幕小助手

> Descriptions are written in Chinese because my poor English level.

你是否在为屏幕时常被灰尘玷污而困扰？请立即使用本清理屏幕小助手！

本助手**郑重承诺**：

* 无需安装，下载即用
* 无需繁琐配置，一键傻瓜式清理
* 无需专业人员协助
* 无需联网
* 不窃取隐私

## 使用方法：

1. 下载最新Release中的构建
2. 运行小助手
3. 是时候清洁你的屏幕了！
4. 清洁完成之后，按ESC键退出清洁程序！

## 构建指南

```bash
git clone  https://github.com/KamijoToma/CleanYourScreen --depth 1
mkdir build
cd build
cmake ..
ninja
```

奇怪的构建问题请Google解决或发Issue

## 已知Bug

* WSL2下GLAD初始化失败，怀疑为WSLg或驱动配置的问题
* Win11下打开助手时会有一段闪屏，目测为GLAD初始化造成
* Win11下内存占用高达150MB+，而且会造成风扇狂转，显卡占用高

## 另一种解决思路

(仅限于Windows系统)

只需要简单地执行

```cmd
START /MIN /WAIT C:\Windows\System32\scrnsave.scr -s
```

即可造成黑屏，点击鼠标退出

~~可惜的是不能跨平台~~

## 正经Readme

学了学LearningOpenGL里的几个小节，简单的在项目里写出了这个技术力很低的小东西，
但是确实对我的屏幕灰尘强迫症起了些许疗效，不用每天都担心屏幕上是不是有灰尘……etc

## Roadmap

- [x] 实现基本的屏幕变黑支持
- [ ] 实装`imgui`实现显示刷新率和调节屏幕色彩的功能（检测屏幕坏点）
- [ ] 减小CPU占用和GPU占用
- [ ] 抑制闪烁
- [ ] 实现Github Actions自动化构建和发布

## License

MIT License