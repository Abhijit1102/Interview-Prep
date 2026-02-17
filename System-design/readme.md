# 🏗️ System Design Notes

This directory contains my learning, notes, and case studies related to **System Design for Software Engineering interviews**.

The purpose is not only to understand how systems work, but to learn **how to think like an engineer who designs scalable production systems**.

I am documenting concepts in a revision-friendly way so they can be quickly reviewed before interviews.

---

## What This Folder Contains

* High Level Design (HLD) explanations
* Low Level Design (LLD) concepts
* Architecture diagrams (where applicable)
* Real-world system breakdowns
* Tradeoffs and decision reasoning

This is a learning-first repository — clarity is prioritized over complexity.

---

## 📚 Core Concepts

### 1. Basics

* Client–Server Architecture
* Latency vs Throughput
* Horizontal vs Vertical Scaling
* Availability vs Consistency

### 2. Networking

* DNS resolution
* HTTP vs HTTPS
* REST APIs
* WebSockets
* CDNs

### 3. Databases

* SQL vs NoSQL
* Indexing
* Replication
* Sharding / Partitioning
* ACID properties
* CAP Theorem
* Eventual Consistency

### 4. Caching

* Why caching is needed
* Cache-aside strategy
* Write-through & Write-back
* Cache invalidation
* Redis basics

### 5. Load Handling

* Load Balancers
* Health checks
* Sticky sessions
* Auto scaling

### 6. Distributed Systems

* Consistent Hashing
* Leader Election
* Heartbeats
* Distributed Locks

### 7. Asynchronous Processing

* Message Queues
* Pub/Sub architecture
* Kafka basics
* Background workers
* Job queues

### 8. Reliability & Security

* Rate Limiting
* Circuit Breaker
* Retries & Backoff
* Monitoring & Logging
* Authentication vs Authorization
* API Keys, JWT, OAuth

---

## 🧪 Case Studies (Planned & Ongoing)

Each case study will include:

* Requirements clarification
* Capacity estimation
* API design
* Database schema idea
* Scaling strategy
* Bottlenecks & optimizations

Planned systems:

* URL Shortener (like bit.ly)
* Chat Application (WhatsApp)
* Notification System
* Social Media Feed (Twitter/Instagram)
* File Storage System (Google Drive)
* Video Streaming (YouTube - conceptual)
* Payment System (high-level)

---

## 🎯 Goal

The goal is to:

* Learn how large-scale systems actually work
* Develop structured thinking during interviews
* Explain designs clearly on a whiteboard

I am focusing on **reasoning and tradeoffs**, not memorizing fixed answers.

---

## 🧠 My Approach

While studying a system I always ask:

* What breaks first?
* Where is the bottleneck?
* How does it scale to 10× users?
* How is data kept consistent?
* What happens if a service crashes?

If a design cannot handle failure, it is not production ready.

---

## 📌 Important Note

These notes are written as a personal learning journal.
They will continuously improve as my understanding of distributed systems grows.

---

**Work in progress — continuously updated during interview preparation.**
