                                                                       GENERAL INFO
  Stock Exchange Simulator is a console application that allows you to set up a client's account and trade ETF or turbo certificates or act as a broker who observes and manages clients shares.

  As a client, you can create an account, complete the necessary information and choose a broker who will be responsible for trading your shares. There are several brokers to choose from, each broker will charge a different commission on the transaction. After creating an account, you can put money into your wallet and then buy the first shares, which you can  sell at the most favorable for you moment. After login you can also check charts of shares that you have bought, change your actual broker or check your brokers advices.

  As a broker, after logging in to your account, you have access to your clients' shares, all stocks on the market and you can view charts of all stocks on the market.

                                                                       OTHER INFO
- The application was written in C ++ according to the paradigm of object-oriented programming. 
- I used SFML graphics library to create stock charts. There is a example of chart:
![image](https://user-images.githubusercontent.com/93645494/147418409-2ff38a5e-6e59-4caf-9f89-cf84f430655c.png)

- The update of the stock value takes place in the background of the program, and the algorithm for calculating the stock value is based on randomness.
- Algorithm of the brokers advices is based on the moving average of the last 100 stocks. 
