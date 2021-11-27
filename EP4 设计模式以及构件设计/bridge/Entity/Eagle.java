package bridge.Entity;

import bridge.Bird;
import bridge.behavior.FlyBehavior;
import bridge.behavior.SwimBehavior;


/**
 * @program: algorithm
 * @description:
 * @author: CTGU_LLZ(404name)
 * @create: 2021-11-27 12:56
 **/
public class Eagle extends Bird {

    public Eagle(FlyBehavior behavior, SwimBehavior swimBehavior) {
        super(behavior, swimBehavior);
    }

    @Override
    public void display() {
        System.out.println("-------老鹰--------");
        super.display();
    }
}
