# Coin-Toss
## Introduction
Coin-Toss is a program that tries to simulate stock trades on the market based on past information. It allows individuals to create trading bots and test it against real-life trading environment.

## Architecture
### Namespaces and Classes
#### *Data*
Stores any information relevant to generation/maintenance of data. classes includes:
* **DataManager** - manages initialization and update of data 
* **Data** - main class for reading in and representing stock data
* **QueData** - class inherited from Data, deals with market que of stocks
#### *Market*
Main engine of the program. Used to store trading information of a stock market. classes includes:
* **Market** - main class for the program; stores data of stocks, and broker objects. Uses Datamanager to initialize/update stock information and informs broker of the change.
* **Broker** - manages a set of Traders, informs trader of the status of its orders; and informing them of updated data.
* **Trader** - manages a set of TraderStockPage, updates their trades and keep track of any other relevant data of a real-life trader (ie. currentBal).
* **TraderStockPage** - main class for running the trading algorithm for a stock; also keeps track of its own relevant data.
#### *Stock*
Manages any information relevant to an attribute of stock. classes includes:
* **Stock** - class that holds all information relevant to a stock
* **StockRecord** - stores a record of stock
* **CandleStick** - candlestick representation for the stock - derive changes from market que !!ASSUMES TRADE OCCURS EVEN IF IT IS CANCELED!!




