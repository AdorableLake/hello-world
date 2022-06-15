/*
挑战：将多个模式分解成函数和循环。
在这项挑战中，需要收集宝石并打开开关。首先要识别出收集宝石和激活开关的模式。然后要为每种模式编写一个函数，并计算出需要使用循环调用那些函数的次数。
*/
func turnAround() {            //定义转身函数
    for i in 1 ... 2 {
        turnLeft()
    }
}
func toggleSiwtchTwice() {    //定义打开一侧的开关的函数
    for i in 1 ... 2 {
        moveForward()
        toggleSwitch()
    }
}
func collectGemTwice() {      //定义收集一侧的宝石的函数
    for i in 1 ... 2 {
        moveForward()
        collectGem()
    }
}
func moveTwice() {            //定义移动两次
    for i in 1 ... 2 {
        moveForward()
    }
}
func OneLine() {             //定义一次流程
    turnLeft()
    toggleSiwtchTwice()
    turnAround()
    moveTwice()
    collectGemTwice()
    turnAround()
    moveTwice()
    turnRight()
    moveForward()
}

for i in 1 ... 3 {
    OneLine()
}
