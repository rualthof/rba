#include"gtest/gtest.h" 
#include "GameBoard.h"

TEST(GameBoard, board_n_players){
	GameBoard myBoard(4);
	ASSERT_EQ(4,myBoard.players());
}

TEST(GameBoard, player_roll){
	GameBoard myBoard(2);
	ASSERT_THROW(myBoard.roll(2,3),std::exception); //No existant player
	ASSERT_NO_THROW(myBoard.roll(0,3)); //player 0 downs 3 pins
	ASSERT_EQ(0, myBoard.nextFrame(0)); //player istill on frame 0
	ASSERT_NO_THROW(myBoard.roll(0,4)); //2nd roll for the frame 
	ASSERT_EQ(1, myBoard.nextFrame(0)); //Player 0 still on frame 0 } 
}
TEST(GameBoard, player_invalid_roll){
	
	GameBoard myBoard(1);
	ASSERT_THROW(myBoard.roll(0,11),std::runtime_error); //only 10 pins
	ASSERT_NO_THROW(myBoard.roll(0,4)); //No existant player
	//ASSERT_THROW(myBoard.roll(0,7), std::runtime_error);
}

int main(int argc, char ** argv){ 
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}





