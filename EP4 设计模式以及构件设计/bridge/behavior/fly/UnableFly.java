package bridge.behavior.fly;

import bridge.behavior.FlyBehavior;

/**
 * @program: algorithm
 * @description:
 * @author: CTGU_LLZ(404name)
 * @create: 2021-11-27 12:51
 **/
public class UnableFly implements FlyBehavior {
    public UnableFly() {
    }

    @Override
    public void fly() {
        System.out.println("飞不起来");
    }
}
