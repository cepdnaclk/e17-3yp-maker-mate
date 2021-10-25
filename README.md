
[//]: # "Please refer the instructions in below URL for the configurations"
[//]: # "https://projects.ce.pdn.ac.lk/docs/how-to-add-a-project"

# Maker Mate

## Overview
For this project specific case, Maker Mate enables the lab users to apply for the project/ experiment requirements online and collect tools and equipment accordingly from a pickup locker while the lab admin can manage the entire inventory online with ease. Maker Mate can take similar role but for different use case on demand.

## Introduction
Maker Mate is a system which assits the makers in computer engineering department. It consists an information console, pickup locker and an inventory management system.The console shows the details about the tools and equipments in the labrotary and also the web version can be accessed from anywhere. The pickup locker is used to pick-up and return the pre-ordered package of components. The Maker Mate provide 24 hour online service to the students and admin. The administrators will be able to manage the inventory through this system more efficiently and in real time.

## Goals
* Creating a fully functional inventory management system for the Maker Space.
* Developing a sample locker which can be accessed by authorized user. 
* Developing a user interface to navigate and document users with access to pick-up locker.

## Product Architecture

![Maker Mate Architecture](docs/assets/img/animations/product-architecture.gif)


## Tech Stack

#### Hardware
* Arduino
* Raspery pi

#### Web Interface
##### <u>Front End</u>
* VUE.js
* HTML
* CSS
* Bootstrap
##### <u>Back End</u>
* Laravel
* Mysql
##### <u>Mobile Client</u>
* Flutter

## Budget

|    Item                                           | Unit Price (LKR)           | Quantity  |  Cost                      |
| :---------:                                       | :--------------:           | :----:    | :----:                     |
| Raspberry Pi 4B 2GB/4GB                           |9,250.00 - 14,650.00        |    1      |9,250.00 - 14,650.00        |      
| 7"-15" Capacitive Touch Screen                    |11,700.00 - 60,000.00       |    1      |11,700.00 - 60,000.00       |
| Ultrasonic Sensor                                 |250.00 	                   |    1 	   |250.00 	                    |
| ESP-01S WiFi Relay Module                         |365.00                      |    1      |365.00                      | 
| Solenoid Lock 12V                                 |890.00                      |    1      |890.00                      |
| 4x4 Key Pad module + frame                        |250.00 + casting cost       |    1      |250.00 + casting cost       |
| Raspberry PI 4 Power Supply AC 100-240V DC 5V 3A  |675.00                      |    1      |675.00                      |
| Power Supply Adapter 3 PIN AC/DC 12V 2A           |420.00                      |    1      |420.00                      |
| Others *                                          |-                           |    -      |5000.00                     |
|                                                   |                            |           |                            |
| **Total**                                         |-                           |    -      |**28,800.00 - 82,500.00**   |

## Task List

- [x] Collect details about all the tools & equipment stored in Maker Space
- [x] Categorize them and plan how 3D models, Instruction sheets, Catalogs and Data sheets collected and connected
- [x] Design database model
- [x] Prepare moch-ups for GUIs
- [x] Build the back-end program with the required user roles
- [x] Test Inventory Management system
- [x] Implement required API call to connect MakerMate and inventory mangt.system
- [] Get the QEMU emulator for Raspberry Pi emulation and get some hands on experience to design console UI.
- [ ] Learn interfacing webapp with raspberry pi
- [ ] Build UI interface for flutter mobile app (in charge - @Thanujan96)
- [ ] Complete 3D modeling of Information console

- [ ] add next steps

## Team Members

1. E/17/201 Thilini Madushani [[Website](http://www.thilini98.me/), [Email](mailto:e17201@eng.pdn.ac.lk)]
2. E/17/342 Thanujan Tharmapalan [[Website](https://github.com/thanujan96), [Email](mailto:e17342@eng.pdn.ac.lk)]
3. E/17/194 Madhushan Ramalingam [[Website](https://www.drmadhushan.me/), [Email](mailto:drmadhushan@gmail.com)]

## Supervisors
1. Dr. Isuru Nawinne [[Website](http://www.ce.pdn.ac.lk/academic-staff/isuru-nawinne/), [Email](mailto:isurunawinne@eng.pdn.ac.lk)]
2. Dr. Mahanama Wickramasinghe [[Website](http://www.ce.pdn.ac.lk/2021/05/02/dr-mahanama-wickramasinghe/), [Email](mailto:mahanamaw@eng.pdn.ac.lk)]

## Links
1. [Project page](https://cepdnaclk.github.io/e17-3yp-maker-mate)
2. [GitHub repo](https://github.com/cepdnaclk/e17-3yp-maker-mate)
3. [Department of computer engineering](http://ce.pdn.ac.lk)

## Publications
1. [Semester 7 report](https://cepdnaclk.github.io/e17-3yp-maker-mate)
2. [Semester 7 slides](https://cepdnaclk.github.io/e17-3yp-maker-mate)
3. [Semester 8 report](https://cepdnaclk.github.io/e17-3yp-maker-mate)
4. [Semester 8 slides](https://cepdnaclk.github.io/e17-3yp-maker-mate)
5. Author1, Author2 and Author2 "Research paper title" in Conference name 2021. [Download PDF ](https://cepdnaclk.github.io/e17-3yp-maker-mate)
