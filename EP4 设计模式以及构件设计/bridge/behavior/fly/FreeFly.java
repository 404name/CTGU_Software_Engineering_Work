package bridge.behavior.fly;

import bridge.behavior.FlyBehavior;

/**
 * @program: algorithm
 * @description: 实现类
 * @author: CTGU_LLZ(404name)
 * @create: 2021-11-27 12:50
 **/
public class FreeFly implements FlyBehavior {
    public FreeFly() {
    }

    @Override
    public void fly() {
        System.out.println("自由的飞翔");
    }
}
