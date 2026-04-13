# Multi-Door Setup

## Naming convention
Use predictable identifiers:
- site: hq
- building: main-office
- floor: f1
- door: front-door

Example full door id:
`hq.main-office.f1.front-door`

## Suggested structure
- sites
- buildings
- doors
- door groups
- user roles
- schedules

## Door groups
Use groups for shared access policy:
- office-staff
- engineering-lab
- deliveries
- plant-room

## Rules
- each controller maps to exactly one primary door id
- each unlock command targets one door id
- access is evaluated server-side against role, schedule, and door group membership

## Scaling notes
- keep topic names predictable
- assign unique credentials per controller
- do not clone firmware images with reused secrets
- document physical install location for each device
