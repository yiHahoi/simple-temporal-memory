#ifndef STM_H
#define STM_H
#include <vector>
#include "column.h"
#include "cell_counter.h"
class Stm
{
public:
	Stm();
	~Stm();

	//init
	void preInitCellsPerColumn(int numCells){initCells = numCells;}
	void preInitNumColumns(int numColumns){initColumns = numColumns;}
	void preInitMaxCellConnections(int numConnections){initMaxCellConnections = numConnections;}
	void preInitNumInputConnections(int numConnections){initNumInputConnections = numConnections;}
	void init();
	//input
	void setColumnActive(int col_index); ////////future: use a better way //////////////////////
	void clearActiveColumns(); ////////future: use a better way //////////////////////
	
	//compute active
	//make predictions
	void process();
	
	//output predictions	
	bool isColumnPredicted(int col_index); ///////future: make private ///////////////////////////

	//other settings
	void setLearning(bool learning){learn = learning;}
	bool getLearning(){return learn;}
	int getCellsPerColumn(){return numCellsPerColumn;}
	int getNumColumns(){return numColumns;}
	void printSettings();
	void printStatus();
	void printInnerds();
	void printAll();
	

private:
	std::vector<int> inputs_vec;//store the columns
	std::vector<Column*> column_vec;//store the columns
	std::vector<Cell*> cell_pre_active_vec;
	std::vector<Cell*> cell_temp_active_vec;
	std::vector<Cell*> cell_set_active_vec;
	std::vector<Cell*> cell_make_connections_vec;
	std::vector<Cell_counter*> cell_count_predicted_vec;

	bool has_init = false;
	int initCells;
	int initColumns;
	int initMaxCellConnections;
	int initNumInputConnections;

	int current_step = 0;
	int numCellsPerColumn;
	int numColumns;
	int maxCellConnections;
	int numInputConnections;
	bool learn;
	double learn_increment = 0.05;//future: needs setter
	double learn_decrement = 0.05;//future: needs setter
	double predicted_min_strength = 0.2;//future: needs setter
	int predicted_min_active = 1;//future: needs setter
	int randSeed;
	
	void initConnections();
	void compute_active();
	void make_predictions();
	void new_cell_connection(Cell* c_send, Cell* c_receive);
	void new_cell_connection(Cell* c_send, Cell* c_receive, double strength);
	void delete_cell_connection(Cell_connection* connection);
	void clean();
};
#endif
