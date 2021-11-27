package bridge;

import bridge.Entity.Eagle;
import bridge.Entity.Penguin;
import bridge.behavior.fly.FreeFly;
import bridge.behavior.fly.UnableFly;
import bridge.behavior.swim.AbleSwim;
import bridge.behavior.swim.UnableSwim;


/**
 * @program: Client
 * @description:
 * @author: CTGU_LLZ(404name)
 * @create: 2021-11-27 12:53
 **/
public class Client{
    public Bird bird;

    public static void main(String[] args) {
        Bird eagle = new Eagle(new UnableFly(),new AbleSwim());
        eagle.display();
        Bird penguin = new Penguin(new FreeFly(),new UnableSwim());
        penguin.display();
    }
}
