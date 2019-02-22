using namespace std;

class HungryCowsEasy{
	public:
    	vector< int > findFood(vector< int > cowPositions, vector< int > barnPositions){
            vector< int > pos;

            for(int i = 0 ; i < cowPositions.size() ; i++){
                int r = 1e9;
                int cord = -1;

                for(int j = 0 ; j < barnPositions.size() ; j++){
                    int dis = abs(barnPositions[j] - cowPositions[i]);
                    int disr = abs(r - cowPositions[i]);

                    if(dis < disr){
                        r = barnPositions[j];
                        cord = j;
                    }else if(dis == disr){
                        if(r > barnPositions[j]){
                            r = barnPositions[j];
                            cord = j;
                        }
                    }
                }

                pos.push_back(cord);
            }

            return pos;
        }
};