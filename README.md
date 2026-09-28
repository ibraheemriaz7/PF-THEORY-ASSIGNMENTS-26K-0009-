# PF-THEORY-ASSIGNMENTS-26K-0009-
# PF Assignment 01

**Name:** MUHAMMAD IBRAHEEM RIAZ

**Roll No:** 26K - 0009


* PAC AND IPO ARE MADE AFTER THE CODES

## Section A
- [Section A Q 1,2](<PF ASSIGNMENT 01/Section A Q 1,2.jpeg>)
- [Section A Q3](<PF ASSIGNMENT 01/Section A Q3.jpeg>)
- [Section A Q4,5](<PF ASSIGNMENT 01/Section A Q4,5.jpeg>)

## Section B

| Question | C File | Pseudocode |
|----------|--------|------------|
| Q1 | [C file](<PF ASSIGNMENT 01/Section B Q1 (C file).c>) | [Part 1](<PF ASSIGNMENT 01/Section B Q1 1st part Pseudo Code.jpeg>), [Part 2](<PF ASSIGNMENT 01/Section B Q1 2nd part Pseudo Code.jpeg>) |
| Q2 | [C file](<PF ASSIGNMENT 01/Section B Q2 ( C file).c>) | [Pseudocode](<PF ASSIGNMENT 01/Section B Q2 Pseudo Code.jpeg>) |
| Q3 | [C file](<PF ASSIGNMENT 01/Section B Q3 (C file).c>) | [Pseudocode](<PF ASSIGNMENT 01/Section B Q3 Pseudo Code.jpeg>) |
| Q4 | [C file](<PF ASSIGNMENT 01/Section B Q4 (C file).c>) | [Pseudocode](<PF ASSIGNMENT 01/Section B Q4 Pseudo Code.jpeg>) |
| Q5 | [C file](<PF ASSIGNMENT 01/Section B Q5 (C file).c>) | - |
| Q6 | [C file](<PF ASSIGNMENT 01/Section B Q6 (C file).c>) |

# Section B: IPO & PAC CHARTS

---

## Question 1: Hotel Booking System

### Problem Analysis Chart (PAC)
| Given Data (Input) | Processing / Operations | Required Output |
| :--- | :--- | :--- |
| • Total guests ($N$)<br>• Season (`Peak` / `Off-Peak`)[cite: 1]<br>• Room Type (`Standard`, `Deluxe`, `Suite`)[cite: 1]<br>• Nights stayed (`nights`)[cite: 1] | 1. Loop through $N$ guests.<br>2. Determine base rate per night based on `Season` and `Room Type`.[cite: 1]<br>3. Compute base price: $\text{Base Price} = \text{rate} \times \text{nights}$.[cite: 1]<br>4. Check if `nights` > 7; if so, calculate 15% discount: $\text{Discount} = \text{Base Price} \times 0.15$.[cite: 1]<br>5. Compute guest total: $\text{Total} = \text{Base Price} - \text{Discount}$.[cite: 1]<br>6. Accumulate into running hotel revenue: $\text{Total Revenue} = \text{Total Revenue} + \text{Total}$.[cite: 1] | • Final price for each guest[cite: 1]<br>• Hotel total revenue[cite: 1] |

### IPO Chart
| Input | Processing | Output |
| :--- | :--- | :--- |
| • `N` (Total Guests)<br>• `season`<br>• `roomType`<br>• `nights` | 1. Input guest details.<br>2. Evaluate room rate based on season & room type.<br>3. Calculate total price and long-stay discount.<br>4. Add guest price to total revenue.<br>5. Print guest bill and total revenue. | • `guestTotal`<br>• `totalRevenue` |

---

## Question 2: Elevator Simulation

### Problem Analysis Chart (PAC)
| Given Data (Input) | Processing / Operations | Required Output |
| :--- | :--- | :--- |
| • Initial floor ($0$)[cite: 1]<br>• Number of requests ($N$)[cite: 1]<br>• List of requested floors (`requestedFloor`)[cite: 1] | 1. Set `currentFloor = 0`.[cite: 1]<br>2. Loop through $N$ requests:<br>&nbsp;&nbsp;&nbsp;&nbsp;a. Compare `requestedFloor` with `currentFloor`.[cite: 1]<br>&nbsp;&nbsp;&nbsp;&nbsp;b. If `requestedFloor` > `currentFloor` $\rightarrow$ Print "Moving Up".[cite: 1]<br>&nbsp;&nbsp;&nbsp;&nbsp;c. If `requestedFloor` < `currentFloor` $\rightarrow$ Print "Moving Down".[cite: 1]<br>&nbsp;&nbsp;&nbsp;&nbsp;d. If `requestedFloor` == `currentFloor` $\rightarrow$ Print "Doors Opening".[cite: 1]<br>&nbsp;&nbsp;&nbsp;&nbsp;e. Update `currentFloor = requestedFloor`.[cite: 1] | • Direction message ("Moving Up", "Moving Down", "Doors Opening")[cite: 1]<br>• Updated floor status |

### IPO Chart
| Input | Processing | Output |
| :--- | :--- | :--- |
| • `currentFloor` (Initial = 0)<br>• `N` (Total Requests)<br>• `requestedFloor` | 1. Read target floor.<br>2. Compare `requestedFloor` with `currentFloor`.<br>3. Output movement directional status message.<br>4. Set `currentFloor = requestedFloor`. | • Status message<br>• Updated `currentFloor` |

---

## Question 3: Class Result Processing

### Problem Analysis Chart (PAC)
| Given Data (Input) | Processing / Operations | Required Output |
| :--- | :--- | :--- |
| • Number of students ($N$)[cite: 1]<br>• 5 subject marks per student (`m1`, `m2`, `m3`, `m4`, `m5`)[cite: 1] | 1. Loop through $N$ students.<br>2. Calculate total and average: $\text{Avg} = \frac{\sum \text{marks}}{5}$.[cite: 1]<br>3. Check for subject deficiency: If any mark < 33, flag `deficiency = true`.[cite: 1]<br>4. Determine final result classification:<br>&nbsp;&nbsp;&nbsp;&nbsp;• If `deficiency == true` $\rightarrow$ "Fail — Subject Deficiency".[cite: 1]<br>&nbsp;&nbsp;&nbsp;&nbsp;• Else if $\text{Avg} \ge 80$ $\rightarrow$ "Distinction".[cite: 1]<br>&nbsp;&nbsp;&nbsp;&nbsp;• Else if $\text{Avg} \ge 60$ $\rightarrow$ "Pass".[cite: 1]<br>&nbsp;&nbsp;&nbsp;&nbsp;• Else $\rightarrow$ "Fail".[cite: 1] | • Total Marks<br>• Average Marks<br>• Final Result Classification[cite: 1] |

### IPO Chart
| Input | Processing | Output |
| :--- | :--- | :--- |
| • `N` (Number of students)<br>• `m1, m2, m3, m4, m5` (5 Subject Marks) | 1. Read student subject marks.<br>2. Sum marks and compute average.<br>3. Check if any subject mark < 33.<br>4. Classify performance using average and deficiency rule. | • `sum`<br>• `average`<br>• `resultStatus` |

---

## Question 4: Online Shopping Bill Calculator

### Problem Analysis Chart (PAC)
| Given Data (Input) | Processing / Operations | Required Output |
| :--- | :--- | :--- |
| • Quantity ($q$)[cite: 1]<br>• Unit Price ($p$)[cite: 1]<br>• Discount % ($d$)[cite: 1]<br>• Tax % ($t$)[cite: 1] | 1. Input inputs and validate: If $q \le 0$, $p \le 0$, $d < 0$, or $t < 0$, display error and terminate.[cite: 1]<br>2. Compute Subtotal: $s = q \times p$.[cite: 1]<br>3. Compute Discounted Amount: $a = s - \frac{s \times d}{100}$.[cite: 1]<br>4. Compute Final Bill: $\text{Bill} = a + \frac{a \times t}{100}$.[cite: 1]<br>5. Generate document and display output.[cite: 1] | • Error message (if invalid)[cite: 1]<br>• Subtotal ($s$)[cite: 1]<br>• Discounted Amount ($a$)[cite: 1]<br>• Final Bill Amount[cite: 1] |

### IPO Chart
| Input | Processing | Output |
| :--- | :--- | :--- |
| • `q` (Quantity)<br>• `p` (Price)<br>• `d` (Discount %)<br>• `t` (Tax %) | 1. Validate input entries ($q, p, d, t > 0$).<br>2. Calculate subtotal ($s = q \times p$).<br>3. Calculate discounted price ($a$).<br>4. Calculate tax and final bill.<br>5. Render bill document. | • Error message (if invalid)<br>• Itemized Bill Document<br>• `finalBill` |

---

## Question 5: Smart Campus Parking Management System

### Problem Analysis Chart (PAC)
| Given Data (Input) | Processing / Operations | Required Output |
| :--- | :--- | :--- |
| • Vehicle type (`C`, `B`, `V`)[cite: 1]<br>• User category (`F`, `S`, `G`)[cite: 1]<br>• Permit status (`Y`/`N`)[cite: 1]<br>• Emergency status (`Y`/`N`)[cite: 1]<br>• Number of arriving vehicles[cite: 1] | 1. Validate inputs via nested validation loop.[cite: 1]<br>2. Apply eligibility & zone rules:<br>&nbsp;&nbsp;&nbsp;&nbsp;• Faculty $\rightarrow$ Zone A (Cap: 20)[cite: 1]<br>&nbsp;&nbsp;&nbsp;&nbsp;• Student $\rightarrow$ Zone B (Cap: 40)[cite: 1]<br>&nbsp;&nbsp;&nbsp;&nbsp;• Visitor $\rightarrow$ Zone C (Cap: 15)[cite: 1]<br>&nbsp;&nbsp;&nbsp;&nbsp;• Emergency vehicles bypass permit check.[cite: 1]<br>3. Handle special vehicle rules (Vans consume 2 spaces in Zone C).[cite: 1]<br>4. Verify capacity; assign zone if space available or apply redirect/rejection logic.[cite: 1]<br>5. Update zone occupancy and counters.[cite: 1] | • Assigned zone and remaining capacity[cite: 1]<br>• Rejection reason (if applicable)[cite: 1]<br>• Final summary report (accepted/rejected counts, vehicle type counts, zone with highest occupancy, facility full status)[cite: 1] |

### IPO Chart
| Input | Processing | Output |
| :--- | :--- | :--- |
| • `vehicleType`<br>• `userCategory`<br>• `hasPermit`<br>• `isEmergency`<br>• Initial Zone Capacities (A:20, B:40, C:15) | 1. Loop input and validate data entries.<br>2. Evaluate access eligibility based on user type, permit, and emergency status.<br>3. Check zone space availability and vehicle space footprint.<br>4. Increment parking counts and update capacity.<br>5. Compute highest occupied zone and total facility state. | • Rejection / Acceptance status<br>• Updated zone capacities<br>• Final parking summary report |

---

## Question 6: Smart EV Charging and Parking Management System

### Problem Analysis Chart (PAC)
| Given Data (Input) | Processing / Operations | Required Output |
| :--- | :--- | :--- |
| • Vehicle type (`E`/`H`)[cite: 1]<br>• Current Battery % (`battery`)[cite: 1]<br>• Required Charging % (`reqBattery`)[cite: 1]<br>• Parking Hours (`hours`)[cite: 1]<br>• Current Time (`time`)[cite: 1]<br>• Member Status (`Y`/`N`)[cite: 1]<br>• Disabled Priority (`Y`/`N`)[cite: 1]<br>• Station Available (`Y`/`N`)[cite: 1] | 1. Check station availability and vehicle qualification.[cite: 1]<br>2. Determine Charging Priority:<br>&nbsp;&nbsp;&nbsp;&nbsp;• Priority 1 (Emergency): `battery` $\le$ 15% AND `reqBattery` $\ge$ 80%[cite: 1]<br>&nbsp;&nbsp;&nbsp;&nbsp;• Priority 2 (Priority Customer): `disabled` == Y OR (`membership` == Y AND `battery` $\le$ 30%)[cite: 1]<br>&nbsp;&nbsp;&nbsp;&nbsp;• Priority 3 (Normal): Otherwise[cite: 1]<br>3. Compute Charging Cost (Peak: 17:00–22:00 @ Rs. 50; Off-Peak: @ Rs. 35) & discounts.[cite: 1]<br>4. Compute Parking Cost (0–2h: Rs. 200, 2–5h: Rs. 400, >5h: Rs. 700; Free for disabled).[cite: 1]<br>5. Apply 20% parking discount for members.[cite: 1]<br>6. Check parking duration warning (> 8 hours).[cite: 1] | • Vehicle type & battery levels[cite: 1]<br>• Charging priority[cite: 1]<br>• Peak / Off-Peak status[cite: 1]<br>• Itemized costs (Charging cost, Parking cost, Discounts)[cite: 1]<br>• Final payable bill amount[cite: 1]<br>• Duration warning message[cite: 1] |

### IPO Chart
| Input | Processing | Output |
| :--- | :--- | :--- |
| • `vehicleType`<br>• `battery`<br>• `reqBattery`<br>• `hours`<br>• `time`<br>• `membership`<br>• `disabled`<br>• `station` | 1. Validate station availability and vehicle eligibility.<br>2. Evaluate charging priority tier.<br>3. Determine time slot (Peak vs Off-Peak) and calculate charging rate.<br>4. Calculate parking fee structure and apply disability/membership discounts.<br>5. Sum total bill and evaluate long-stay warning. | • Charging Priority Tier<br>• Peak/Off-Peak Indicator<br>• `chargingCost`, `parkingCost`<br>• `chargingDiscount`, `parkingDiscount`<br>• `finalBill`<br>• Duration Warning Message |
```
