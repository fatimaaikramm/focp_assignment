# focp_assignment
C++ Program for Relief Supply Distribution System 
# Flood Relief Allocation System

**GitHub Repository:** https://github.com/fatimaaikramm/focp_assignment

## 1. Group Members and Contributions

- **Fatima Ikram:** Logic building, coding, and GitHub repository management.
- **Mustabshirah Shahbaz:** Logic building, documentation, and flowchart design.

## 2. Project Overview

This C++ program distributes relief resources among five flood affected villages. It calculates each village's need score, selects a relief action, checks available resources, and updates the remaining stock.

The program starts with 5 trucks and 120 supply packs.

## 3. Need Score Formula

**Need Score = Damage Points + Family Points + Flood Points + Route Points + Medical Points + Previous Aid Points**

Scoring rules:
- High damage: +15, Medium: +10, Low: +5
- Families affected: Number of families ÷ 10
- Flood warning: +15
- Damaged route: +10
- Medical need: +25
- Previous aid received: −10

Medical need has the highest weight because of its urgency. The other factors represent damage, flood risk, accessibility, population, and previous assistance.

## 4. Decision Rules

The program selects a relief action based on the need score:

- **70 or more:** Full Relief (2 trucks, 50 packs)
- **50–69:** Standard Relief (1 truck, 30 packs)
- **30–49:** Emergency Kit Only (1 truck, 10 packs)
- **Below 30:** Defer (no resources)

If resources are insufficient, the program tries a smaller relief action before deferring the request. It then updates the remaining resources and counts handled and deferred requests.

## 5. Test Results

**Test Set 1: 5 trucks and 120 packs**

- Riverside Village: Full Relief
- Hilltop Settlement: Defer
- Lakeside Camp: Standard Relief
- Market Town: Defer
- Bridge Colony: Standard Relief
- **Handled:** 3
- **Deferred:** 2
- **Remaining:** 1 truck and 10 packs

**Test Set 2: 5 trucks and 70 packs**

- Riverside Village: Full Relief
- Hilltop Settlement: Defer
- Lakeside Camp: Emergency Kit Only
- Market Town: Defer
- Bridge Colony: Emergency Kit Only
- **Handled:** 3
- **Deferred:** 2
- **Remaining:** 1 truck and 0 packs

In Test Set 2, Lakeside Camp and Bridge Colony received Emergency Kits because there were not enough packs for Standard Relief.

## 6. Limitations and Improvements

Possible improvements include clearer messages explaining fallback decisions, stronger input validation, and allowing users to enter the initial resource quantities.

## 7. Use of AI

We wrote the C++ code ourselves and used AI to understand the assignment, review our logic, and identify bugs. We verified the suggested corrections and can explain our code and flowcharts.

## 8. Conclusion

This project demonstrates how scoring formulas, conditional statements, and resource tracking can help prioritize flood relief when resources are limited.




