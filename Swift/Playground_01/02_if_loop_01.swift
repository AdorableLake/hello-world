//挑战：运用条件、函数和循环来组织代码
func collectOrToggle() {
    if isOnGem {
        collectGem()
    } else if isOnClosedSwitch {
        toggleSwitch()
    }
}
for i in 1 ... 9 {
    moveForward()
    if isBlocked {
        turnLeft()
    }
    collectOrToggle()
}
