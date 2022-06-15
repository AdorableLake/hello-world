/*
挑战：联系发现模式、分解、函数和 for 循环。
*/
func turnAround() {
    turnLeft()
    turnLeft()
}
func OneCorner() {
    moveForward()
    collectGem()
    turnLeft()
    for i in 1 ... 2 {
        moveForward()
        collectGem()
        turnAround()
        moveForward()
        turnLeft()
    }
    moveForward()
    collectGem()
    moveForward()
}
for i in 1 ... 4 {
    OneCorner()
}
