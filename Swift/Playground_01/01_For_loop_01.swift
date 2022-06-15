/*
挑战：将重复模式分解成函数和 for 循环。

在关卡世界中一共有三段阶梯，并且每段阶梯上都有同样一组任务需要执行。
*/
func CollectOnce() {
    for i in 1 ... 2 {    //前进2格
        moveForward()
    }
    turnRight()           //然后右转
    for i in 1 ... 7 {    //再次前进7格
        moveForward()
    }
    toggleSwitch()        //然后打开开关
    for i in 1 ... 2 {    //转身
        turnRight()
    }
    for i in 1 ... 7 {    //返回7格
        moveForward()
    }
    turnRight()           //再次回到原方向
}

for i in 1 ... 3 {
    CollectOnce()
}
