class Command{
	public:
    	static int maxWidth;
        static vector<Command> commandList;
        int priority; //执行优先级
        bool isActive;
        string cmdName;
        string description;
        string error;
    public:
		static cmp(const Command& a,const Command&b){
            return a.priority < b.priority;
        }
    	
    	static void confirmCommandList(){
			sort(commandList.begin(),commandList.end(),cmp);

        }

        static addAndCheckCommand(Command command){
            commandList.push_back(Command);
        }

        void print(){

        }

};