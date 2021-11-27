package bridge.behavior.swim;

import bridge.behavior.SwimBehavior;

/**
 * @program: algorithm
 * @description:
 * @author: CTGU_LLZ(404name)
 * @create: 2021-11-27 13:15
 **/
public class UnableSwim implements SwimBehavior {
    public UnableSwim() {
    }

    @Override
    public void swim() {
        System.out.println("扑腾几下就死了");
    }
}
