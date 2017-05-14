#ifndef GB_H
#define GB_H

#include<vector>
#include<boost/optional.hpp>
class GameBoard{
	public:
	GameBoard(size_t aPlayers)
		:thePlayerFrames(aPlayers,0),
		 thePlayerRolls(aPlayers,0)
	{
		for(auto & myFrames:thePlayerFrames)
			myFrames.resize(10);
	}
	size_t players() const {
		return thePlayerRolls.size();
	}
	void roll(const size_t aPlayerIndex, const size_t aPinsDown){
		if(aPlayerIndex>=players())
			throw std::runtime_error("Invalid players index");
		thePlayerFrames[aPlayerIndex][nextFrame(aPlayerIndex)].roll(aPinsDown);
		++thePlayerRolls[aPlayerIndex];
	}
	size_t nextFrame(const size_t aPlayerIndex) const{
		return thePlayerRolls[aPlayerIndex]/2;
	}

	size_t score(const size_t aPlayerIndex){
		return 0;
	}

	private:
	struct Frame{
		boost::optional<size_t> theFirstRoll;
		boost::optional<size_t> theSecondRoll;

		void roll(const size_t aPinsDown){
			if(aPinsDown>10){
				throw std::runtime_error("only 10 pins in game per frame");
			}	
			if(!theFirstRoll){
				theFirstRoll = aPinsDown;
				return;
			}
			if(aPinsDown + theFirstRoll.get()>10){
				throw std::runtime_error("only 10 pins in game per frame");
			}
		}
	};
	
	typedef std::vector<Frame> Frames;
	std::vector<Frames> thePlayerFrames;
	std::vector<size_t> thePlayerRolls;

};

#endif
