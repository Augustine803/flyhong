

public class J extends Tetromino{
	/*
	 * 提供构造器进行初始化
	 * J型的四格方块的位置
	*/
	public J() {
		cells[0]=new Cell(0,4,Tetris.J);
		cells[1]=new Cell(0,3,Tetris.J);
		cells[2]=new Cell(0,5,Tetris.J);
		cells[3]=new Cell(1,5,Tetris.J);
		states = new State[4];
		states[0] = new State(0,0,0,-1,0,1,1,1);
		states[1] = new State(0,0,-1,0,1,0,1,-1);
		states[2] = new State(0,0,0,1,0,-1,-1,-1);
		states[3] = new State(0,0,1,0,-1,0,-1,1);
	}
}
