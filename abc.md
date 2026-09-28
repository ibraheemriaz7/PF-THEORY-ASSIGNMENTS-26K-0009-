## Section B — IPO Charts, PAC Charts & Flowcharts

> **Note:** The PAC charts below use the standard structure of **Problem, Inputs, Processing/Logic, and Outputs** because the assignment PDF does not prescribe a specific PAC template.

---

# Question 1 — Hotel Booking System

## IPO Chart

| Input                             | Processing                                         | Output              |
| --------------------------------- | -------------------------------------------------- | ------------------- |
| Number of guests (N)              | Repeat for each guest                              | Guest's total price |
| Season (Peak/Off-Peak)            | Select room rate according to season and room type | Discount amount     |
| Room type (Standard/Deluxe/Suite) | Calculate rate × nights                            | Total revenue       |
| Number of nights                  | If nights > 7, apply 15% discount                  |                     |
|                                   | Add each guest's total to total revenue            |                     |

## PAC Chart

| Problem                                      | Inputs                       | Processing / Logic                                                                                               | Outputs                             |
| -------------------------------------------- | ---------------------------- | ---------------------------------------------------------------------------------------------------------------- | ----------------------------------- |
| Calculate hotel booking charges for N guests | N, season, room type, nights | Select rate based on season and room type; calculate price; apply 15% discount if nights > 7; accumulate revenue | Guest total price and total revenue |

## Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[/Input N/]
    B --> C[Set totalRevenue = 0 and guest = 1]
    C --> D{guest <= N?}

    D -- No --> Z[/Display totalRevenue/]
    Z --> AA([End])

    D -- Yes --> E[/Input season, room type, nights/]
    E --> F{Season = Peak?}

    F -- Yes --> G{Room Type?}
    G -- Standard --> H[rate = 5000]
    G -- Deluxe --> I[rate = 8000]
    G -- Suite --> J[rate = 12000]

    F -- No --> K{Room Type?}
    K -- Standard --> L[rate = 3000]
    K -- Deluxe --> M[rate = 5000]
    K -- Suite --> N[rate = 8000]

    H --> O[price = rate × nights]
    I --> O
    J --> O
    L --> O
    M --> O
    N --> O

    O --> P{nights > 7?}
    P -- Yes --> Q[discount = price × 15%]
    P -- No --> R[discount = 0]

    Q --> S[guestTotal = price - discount]
    R --> S

    S --> T[Add guestTotal to totalRevenue]
    T --> U[Display guestTotal]
    U --> V[guest = guest + 1]
    V --> D
```

---

# Question 2 — Elevator Simulation

## IPO Chart

| Input                  | Processing                                 | Output        |
| ---------------------- | ------------------------------------------ | ------------- |
| Number of requests (N) | Start current floor at 0                   | Moving Up     |
| Requested floor        | Compare requested floor with current floor | Moving Down   |
|                        | Update current floor after every request   | Doors Opening |

## PAC Chart

| Problem                                           | Inputs             | Processing / Logic                                                                   | Outputs                           |
| ------------------------------------------------- | ------------------ | ------------------------------------------------------------------------------------ | --------------------------------- |
| Simulate an elevator responding to floor requests | N, requested floor | Compare requested floor with current floor; determine movement; update current floor | Movement message for each request |

## Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[/Input N/]
    B --> C[Set currentFloor = 0 and request = 1]
    C --> D{request <= N?}

    D -- No --> Z([End])

    D -- Yes --> E[/Input requestedFloor/]
    E --> F{requestedFloor > currentFloor?}

    F -- Yes --> G[Display Moving Up]
    F -- No --> H{requestedFloor < currentFloor?}

    H -- Yes --> I[Display Moving Down]
    H -- No --> J[Display Doors Opening]

    G --> K[Set currentFloor = requestedFloor]
    I --> K
    J --> K

    K --> L[request = request + 1]
    L --> D
```

---

# Question 3 — Class Result Processing

## IPO Chart

| Input                    | Processing                                                 | Output                           |
| ------------------------ | ---------------------------------------------------------- | -------------------------------- |
| Number of students (N)   | Input 5 subject marks for each student                     | Average                          |
| 5 marks for each student | Calculate total and average                                | Distinction                      |
|                          | Check whether any mark is below 33                         | Pass                             |
|                          | Classify based on average unless subject deficiency exists | Fail / Fail — Subject Deficiency |

## PAC Chart

| Problem                        | Inputs                    | Processing / Logic                                              | Outputs                     |
| ------------------------------ | ------------------------- | --------------------------------------------------------------- | --------------------------- |
| Process results for N students | N and 5 marks per student | Calculate average; check for any mark below 33; classify result | Average and result category |

## Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[/Input N/]
    B --> C[Set student = 1]
    C --> D{student <= N?}

    D -- No --> Z([End])

    D -- Yes --> E[Set total = 0, subject = 1, deficiency = No]
    E --> F{subject <= 5?}

    F -- No --> G[average = total / 5]
    F -- Yes --> H[/Input mark/]
    H --> I[Add mark to total]
    I --> J{mark < 33?}

    J -- Yes --> K[Set deficiency = Yes]
    J -- No --> L[Continue]

    K --> M[subject = subject + 1]
    L --> M
    M --> F

    G --> N{deficiency = Yes?}

    N -- Yes --> O[Result = Fail - Subject Deficiency]
    N -- No --> P{average >= 80?}

    P -- Yes --> Q[Result = Distinction]
    P -- No --> R{average >= 60?}

    R -- Yes --> S[Result = Pass]
    R -- No --> T[Result = Fail]

    O --> U[/Display average and result/]
    Q --> U
    S --> U
    T --> U

    U --> V[student = student + 1]
    V --> D
```

---

# Question 4 — Online Shopping Bill Calculator

## IPO Chart

| Input               | Processing                            | Output            |
| ------------------- | ------------------------------------- | ----------------- |
| Quantity            | Calculate subtotal = quantity × price | Subtotal          |
| Price per item      | Apply discount                        | Discounted amount |
| Discount percentage | Apply tax                             | Final bill        |
| Tax percentage      | Validate all entered values           | Bill document     |

## PAC Chart

| Problem                           | Inputs                             | Processing / Logic                                                    | Outputs                            |
| --------------------------------- | ---------------------------------- | --------------------------------------------------------------------- | ---------------------------------- |
| Calculate an online shopping bill | Quantity, price, discount %, tax % | Validate inputs; calculate subtotal; discount amount; tax; final bill | Calculation details and final bill |

## Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[/Input quantity, price, discount %, tax %/]

    B --> C{Are all values valid?}

    C -- No --> D[Display Error]
    D --> E([End])

    C -- Yes --> F[subtotal = quantity × price]
    F --> G[discountedAmount = subtotal - subtotal × discount / 100]
    G --> H[finalBill = discountedAmount + discountedAmount × tax / 100]

    H --> I[Store calculation details]
    I --> J[Generate bill document]
    J --> K[/Display final bill/]
    K --> L([End])
```

> **Assumption for the validation flowchart:** quantity must be positive, price must not be negative, and discount/tax percentages must be valid percentages.

---

# Question 5 — Smart Campus Parking and Access Management System

## IPO Chart

| Input                             | Processing                    | Output                |
| --------------------------------- | ----------------------------- | --------------------- |
| Number of expected vehicles       | Validate vehicle information  | Assigned zone         |
| Vehicle type: Car/Bike/Van        | Check permit and category     | Remaining capacity    |
| Category: Faculty/Student/Visitor | Apply eligibility rules       | Accepted/Rejected     |
| Permit: Y/N                       | Check zone capacity           | Reason for rejection  |
| Emergency: Y/N when required      | Update occupancy and counters | Final parking summary |

## PAC Chart

| Problem                          | Inputs                                                               | Processing / Logic                                                                                    | Outputs                                                                               |
| -------------------------------- | -------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------- |
| Manage campus parking and access | Number of vehicles, vehicle type, category, permit, emergency status | Validate data; determine eligibility; check zone capacity; assign zone; update counters and occupancy | Accepted/rejected vehicles, assigned zones, occupancy, remaining capacity and summary |

## Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[/Input N expected vehicles/]

    B --> C[Set Zone A = 0/20, Zone B = 0/40, Zone C = 0/15]
    C --> D[Set accepted = 0, rejected = 0]
    D --> E[Set carCount = 0, bikeCount = 0, vanCount = 0]
    E --> F[Set vehicle = 1]

    F --> G{vehicle <= N?}
    G -- No --> AA[Calculate highest occupancy and campus full status]
    AA --> AB[/Display final summary/]
    AB --> AC([End])

    G -- Yes --> H[/Input vehicle type, category, permit/]

    H --> I{Are vehicle type and category valid?}
    I -- No --> J[Display Invalid Information]
    J --> H

    I -- Yes --> K{Permit is Y or N?}
    K -- No --> J

    K -- Yes --> L{Emergency?}

    L -- Yes --> M[/Input Emergency Y/N/]
    M --> N{Emergency = Y?}

    N -- Yes --> O[Ignore permit requirement]
    N -- No --> P{Permit = Y?}

    L -- No --> P{Permit = Y?}

    P -- No --> Q[Display Rejected - No Valid Permit]
    Q --> R[rejected = rejected + 1]
    R --> S[vehicle = vehicle + 1]
    S --> G

    P -- Yes --> T[Continue to zone eligibility]
    O --> T

    T --> U{Category = Faculty?}

    U -- Yes --> V{Vehicle = Van?}
    V -- Yes --> W{Zone A has space?}
    W -- Yes --> X[Assign Zone A]
    W -- No --> Y[Reject - Zone A Full]

    V -- No --> Z{Vehicle = Car or Bike?}
    Z -- Yes --> AA1{Zone A has space?}
    AA1 -- Yes --> X
    AA1 -- No --> Y

    U -- No --> AB1{Category = Student?}

    AB1 -- Yes --> AC1{Vehicle = Van?}
    AC1 -- Yes --> AD1{Zone C has space?}
    AD1 -- Yes --> AE1[Assign Zone C]
    AD1 -- No --> AF1[Reject - Zone C Full]

    AC1 -- No --> AG1{Vehicle = Bike or Car?}
    AG1 -- Yes --> AH1{Zone B has space?}
    AH1 -- Yes --> AI1[Assign Zone B]
    AH1 -- No --> AJ1[Reject - Zone B Full]

    AB1 -- No --> AK1{Category = Visitor?}

    AK1 -- Yes --> AL1{Vehicle = Van?}
    AL1 -- Yes --> AM1{Zone C has at least 2 spaces?}
    AM1 -- Yes --> AE1
    AM1 -- No --> AN1[Reject - Insufficient Zone C Space]

    AL1 -- No --> AO1{Vehicle = Car or Bike?}
    AO1 -- Yes --> AP1{Zone C has space?}
    AP1 -- Yes --> AE1
    AP1 -- No --> AN1

    X --> AQ[Update Zone A occupancy]
    AI1 --> AR[Update Zone B occupancy]
    AE1 --> AS[Update Zone C occupancy]

    AQ --> AT[accepted = accepted + 1]
    AR --> AT
    AS --> AT

    AT --> AU{Vehicle type = Car?}
    AU -- Yes --> AV[carCount = carCount + 1]
    AU -- No --> AW{Vehicle type = Bike?}
    AW -- Yes --> AX[bikeCount = bikeCount + 1]
    AW -- No --> AY[vanCount = vanCount + 1]

    AV --> AZ[Display assigned zone and remaining capacity]
    AX --> AZ
    AY --> AZ

    AZ --> S

    Y --> BA[rejected = rejected + 1]
    AF1 --> BB[rejected = rejected + 1]
    AJ1 --> BC[rejected = rejected + 1]
    AN1 --> BD[rejected = rejected + 1]

    BA --> S
    BB --> S
    BC --> S
    BD --> S
```

---

# Question 6 — Smart EV Charging and Parking Management System

## IPO Chart

| Input                         | Processing                          | Output               |
| ----------------------------- | ----------------------------------- | -------------------- |
| Vehicle type: EV/Hybrid       | Check charging station availability | Vehicle type         |
| Current battery SOC           | Determine charging eligibility      | Charging priority    |
| Required charging level       | Calculate required charging         | Peak/Off-Peak status |
| Parking duration              | Determine charging rate             | Charging cost        |
| Current time                  | Calculate parking cost              | Parking cost         |
| Membership                    | Apply membership discounts          | Discount             |
| Disabled priority             | Apply parking rules                 | Final payable amount |
| Charging station availability | Display warnings/messages           | Warning/message      |

## PAC Chart

| Problem                                | Inputs                                                                                                           | Processing / Logic                                                                                                                          | Outputs                                                                              |
| -------------------------------------- | ---------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------ |
| Manage EV charging and parking charges | Vehicle type, battery %, required %, parking duration, time, membership, disabled priority, station availability | Check charging eligibility; calculate charging requirement and priority; determine peak/off-peak rate; calculate parking cost and discounts | Charging priority, charging cost, parking cost, discount, final payable and messages |

## Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[/Input vehicle type, battery %, required %, parking hours, current time, membership, disabled priority, station availability/]

    B --> C{Charging station available?}

    C -- No --> D{Vehicle = Hybrid?}
    D -- Yes --> E[Display Charging unavailable - Parking only]
    D -- No --> F[Display No charging slot available]

    C -- Yes --> G{Vehicle = EV?}
    G -- Yes --> H[EV qualifies for charging]
    G -- No --> I{Battery < 40%?}

    I -- Yes --> J[Hybrid qualifies for charging]
    I -- No --> K[Display Vehicle does not qualify for EV charging]

    H --> L{Required level <= current battery?}
    J --> L

    L -- Yes --> M[Charging required = 0]
    L -- No --> N[Calculate required charging = required level - current battery]

    N --> O{Battery <= 15% AND required level >= 80%?}
    M --> P[Determine charging priority]
    O -- Yes --> Q[Priority = Emergency]
    O -- No --> R{Disabled priority = Y OR membership = Y AND battery <= 30%?}

    R -- Yes --> S[Priority = Priority Customer]
    R -- No --> T[Priority = Normal]

    Q --> U[Determine time period]
    S --> U
    T --> U

    U --> V{Time between 5 PM and 10 PM?}

    V -- Yes --> W[Peak rate = Rs 50 per unit]
    V -- No --> X[Off-peak rate = Rs 35 per unit]

    W --> Y{Priority = Emergency?}
    Y -- Yes --> Z[No membership charging discount]
    Y -- No --> ZA{Membership = Y?}

    X --> ZB{Membership = Y?}

    ZA -- Yes --> ZC[Apply 10% charging discount]
    ZA -- No --> ZD[No charging discount]

    ZB -- Yes --> ZE[Apply 20% charging discount]
    ZB -- No --> ZF[No charging discount]

    Z --> ZG[Calculate charging cost]
    ZC --> ZG
    ZD --> ZG
    ZE --> ZG
    ZF --> ZG
    M --> ZG

    E --> ZH[Calculate parking cost]
    F --> ZH
    K --> ZH
    ZG --> ZH

    ZH --> ZI{Disabled priority = Y?}

    ZI -- Yes --> ZJ[Parking cost = 0]
    ZI -- No --> ZK{Parking duration <= 2 hours?}

    ZK -- Yes --> ZL[Parking cost = Rs 200]
    ZK -- No --> ZM{Parking duration <= 5 hours?}

    ZM -- Yes --> ZN[Parking cost = Rs 400]
    ZM -- No --> ZO[Parking cost = Rs 700]

    ZL --> ZP{Membership = Y?}
    ZN --> ZP
    ZO --> ZP

    ZP -- Yes --> ZQ[Apply 20% parking discount]
    ZP -- No --> ZR[No parking discount]

    ZJ --> ZS[Calculate final payable]
    ZQ --> ZS
    ZR --> ZS

    ZS --> ZT{Parking duration > 8 hours?}
    ZT -- Yes --> ZU[Display warning: Parking exceeds 8 hours]
    ZT -- No --> ZV[No warning]

    ZU --> ZW[/Display vehicle, battery, required %, priority, time period, charging cost, parking cost, discount and final payable/]
    ZV --> ZW

    ZW --> ZX([End])
```

---

## End of Section B Charts
