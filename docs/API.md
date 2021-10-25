
[//]: # "Please refer the instructions in below URL for the configurations"
[//]: # "https://projects.ce.pdn.ac.lk/docs/how-to-add-a-project"

# Maker Mate API Documentation

## Overview
#### What is an API?

API stands for Application Programming Interface. An API is a software intermediary that allows two applications to talk to each other.  In other words, an API is the messenger that delivers your request to the provider that you’re requesting it from and then delivers the response back to you.

An API defines functionalities that are independent of their respective implementations, which allows those implementations and definitions to vary without compromising each other. Therefore, a good API makes it easier to develop a program by providing the building blocks.

#### How do APIs work?

![](docs/assets/img/api/api.png)


Application programming interfaces consist of two components:
* Technical specification describing the data exchange options between solutions with the specification done in the form of a request for processing and data delivery protocols
* Software interface written to the specification that represents it

## API Requests 
**host/api/auth/login -> email,pass(data)**     

**host/api/auth/user -> token(auth header)**\
Return the details of the logged in user.

**host/api/auth/orders -> token(auth header)**\
Return the deatils of the orders that have been placed by the user. This will indicate wether the orders are accepted or they are still in progressing stage or weher we can pick them up. This respose will include all the orders that made by the user.

**host/api/auth/orders/{orderid} -> token(auth header)**\
Returns the specific details corresponding to one specific order that has been placed by the user.

**host api/user/orders/id/opt/number -> returns true if it's same as the otp**\
This request is used once the user received the op and need to pick up their package. 

#
## Links
1. [Project page](https://cepdnaclk.github.io/e17-3yp-maker-mate)
2. [GitHub repo](https://github.com/cepdnaclk/e17-3yp-maker-mate)
3. [Department of computer engineering](http://ce.pdn.ac.lk)
