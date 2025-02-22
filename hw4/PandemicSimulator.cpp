//Isil Unveren
//Section 1
//22202444
//
//

#include "PandemicSimulator.h"
#include <fstream>

using namespace std;

PandemicSimulator::PandemicSimulator(const string cityGridFile){
    ifstream file(cityGridFile);
    if (!file.is_open()) {
        throw runtime_error("Could not open file.");
    }

    file >> rows >> cols;
    cityGrid = new CityBlock*[rows];
    string states = "";
    for (int i = 0; i < rows; i++) {
        cityGrid[i] = new CityBlock[cols];
        file >> states;
        int j = 0;
        
        for (char ch : states) {
            int num = ch - '0';
            cityGrid[i][j].state = num;
            j++;
        }
    }
    file.close();
}

PandemicSimulator::~PandemicSimulator() {
    for (int i = 0; i < rows; ++i) {
        delete[] cityGrid[i];
    }
    delete[] cityGrid;
}


void PandemicSimulator::displayCityState(const int time) {
    
    CityBlock** cityTemp = Pandemic(time);

    cout << "City state at day " << time << ":" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << cityTemp[i][j].state;
        }
        cout << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] cityTemp[i];
    }
    delete[] cityTemp;

}

void PandemicSimulator::simulateBlock(const int row, const int col) {

    //If given cooridnate is out of bounds of the city grid
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        return;
    }

    //If coordinate corresponds to an empty block
    if (cityGrid[row][col].state == 0) {
        cout << "Time for block (" << row << ", " << col << ") to be infected: " <<"-1 days." << endl;

        return;
    }
    if (cityGrid[row][col].state == 2) {
        cout << "Time for block (" << row << ", " << col << ") to be infected: " <<"0 days." << endl;
        return;
    }

    //Pandemic method finds infection time of each block in city grid that we create temporarily
    CityBlock** cityTemp = Pandemic();

    //Hold infection time of that city block
    int daysToBeInfected = cityTemp[row][col].infectionTime;
    
    cout << "Time for block (" << row << ", " << col << ") to be infected: " << daysToBeInfected <<" days." << endl;

    //Deleting the temp city grid
    for (int i = 0; i < rows; ++i) {
        delete[] cityTemp[i];
    }
    delete[] cityTemp;
}

void PandemicSimulator::simulatePandemic() {

    Queue BFSQueue;

    //pushing all infected cells to the queue
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (cityGrid[i][j].state == 2) {
                BFSQueue.enqueue(i, j);
                cityGrid[i][j].infectionTime = 0;
            }
        }
    }
    
    int neighborsX[4] = {-1, 1, 0, 0};
    int neighborsY[4] = {0, 0, -1, 1};

    int timeToSpread = 0;
    
    while (!BFSQueue.isEmpty()) {
        
        Node* current = BFSQueue.peek();
        
        int curRow = current->row;
        int curCol = current->col;
        
        int currentTime = cityGrid[curRow][curCol].infectionTime;
        BFSQueue.dequeue();
        
        
        //looking at adjacent city blocks
        for (int i = 0; i < 4; i++) {
            
            int rowAdj = curRow + neighborsX[i];
            int colAdj = curCol + neighborsY[i];

            // adjacent blocks will be infected
            if (rowAdj >= 0 && rowAdj < rows && colAdj >= 0 && colAdj < cols){
                if (cityGrid[rowAdj][colAdj].state == 1 ) {
                    
                    cityGrid[rowAdj][colAdj].infectionTime = currentTime + 1;
                    
                    if(timeToSpread < cityGrid[rowAdj][colAdj].infectionTime){
                        timeToSpread = cityGrid[rowAdj][colAdj].infectionTime;
                    }
                    BFSQueue.enqueue(rowAdj, colAdj);
                    cityGrid[rowAdj][colAdj].state = 2;
                    
                    
                }
                

            }
        }
    }

    //looking at is there any remaining block with state 1 (unreachable)
    bool spreadAll = true;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (cityGrid[i][j].state == 1) {
                spreadAll = false;
                break;
            }
        }
    }

    if (spreadAll) {
        cout << "Minimum time for pandemic to spread to all blocks: " <<  timeToSpread << " days." << endl;
    } else {
        cout << "Pandemic cannot spread to all blocks." << endl;
    }
}

/**
 This method makes spreading process in a temporary city grid
 */
CityBlock** PandemicSimulator::Pandemic(){
    
    //creating a temporary city grid in order not to make permanent changes on actual city grid
    CityBlock** cityTemp = new CityBlock*[rows];
    for (int i = 0; i < rows; ++i) {
        cityTemp[i] = new CityBlock[cols];
        for (int j = 0; j < cols; ++j) {
            cityTemp[i][j] = cityGrid[i][j];
        }
    }

    Queue BFSQueue;

    // pushing infected blocks to queue
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (cityTemp[i][j].state == 2) {
                BFSQueue.enqueue(i, j);
                cityTemp[i][j].infectionTime = 0;
            }
        }
    }

    int neighborsX[4] = {-1, 1, 0, 0};
    int neighborsY[4] = {0, 0, -1, 1};
    int currentTime = 0;

    // Simulate the infection spread up to the given time
    while (!BFSQueue.isEmpty()) {
        int numOfInfected = 0;
        
        Node* n = BFSQueue.peek();
        
        while(n != nullptr){
            numOfInfected++;
            n = n->next;
        }

        //to spread simultaneously from all infected cells it should iterate num of infected cells
        for (int i = 0; i < numOfInfected; ++i) {
            
            Node* cur = BFSQueue.peek();
            
            int curRow = cur->row;
            int curCol = cur->col;
            
            BFSQueue.dequeue();

            //looking at infected cells' neighbors
            for (int i = 0; i < 4; i++) {
                int newRow = curRow + neighborsX[i];
                int newCol = curCol + neighborsY[i];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols){
                    if(cityTemp[newRow][newCol].state == 1 && cityTemp[newRow][newCol].infectionTime == -1) {
                        BFSQueue.enqueue(newRow, newCol);
                        cityTemp[newRow][newCol].infectionTime = currentTime + 1;
                        
                    }
                }
            }
            
        }
        ++currentTime;
    }
    return cityTemp;
}

/**
 This method makes spreading process up to given time in a temporary city grid
 */
CityBlock** PandemicSimulator::Pandemic(int time){
    
    //creating a temporary city grid in order not to make permanent changes on actual city grid
    CityBlock** cityTemp = new CityBlock*[rows];
    for (int i = 0; i < rows; ++i) {
        cityTemp[i] = new CityBlock[cols];
        for (int j = 0; j < cols; ++j) {
            cityTemp[i][j] = cityGrid[i][j];
        }
    }
    Queue BFSQueue;

    // pushing infected blocks to queue
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (cityTemp[i][j].state == 2) {
                BFSQueue.enqueue(i, j);
                cityTemp[i][j].infectionTime = 0;
            }
        }
    }

    int neighborsX[4] = {-1, 1, 0, 0};
    int neighborsY[4] = {0, 0, -1, 1};
    int currentTime = 0;

    // simultaneously spreading infection until current time is equal to the time
    while (!BFSQueue.isEmpty() && currentTime < time) {
        int numOfInfected = 0;
        
        Node* n = BFSQueue.peek();
        
        while(n != nullptr){
            numOfInfected++;
            n = n->next;
        }

        //to spread simultaneously from all infected cells it should iterate num of infected cells
        for (int i = 0; i < numOfInfected; ++i) {
            
            Node* cur = BFSQueue.peek();
            
            int curRow = cur->row;
            int curCol = cur->col;
            
            BFSQueue.dequeue();

            //looking at infected cells' neighbors
            for (int i = 0; i < 4; i++) {
                int newRow = curRow + neighborsX[i];
                int newCol = curCol + neighborsY[i];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols){
                    if(cityTemp[newRow][newCol].state == 1 && cityTemp[newRow][newCol].infectionTime == -1) {
                        BFSQueue.enqueue(newRow, newCol);
                        cityTemp[newRow][newCol].state = 2;
                        cityTemp[newRow][newCol].infectionTime = currentTime + 1;
                        
                    }
                }
            }
            
        }
        ++currentTime;
    }
    return cityTemp;
}

