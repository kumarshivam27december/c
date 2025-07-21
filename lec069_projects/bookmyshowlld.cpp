/*


###  Core Entities

1. **User**

   * `user_id` (PK)
   * `name`
   * `email`
   * `phone`
   * `password_hash`
   * `role` (e.g., customer, admin)

2. **Movie**

   * `movie_id` (PK)
   * `title`
   * `language`
   * `genre`
   * `duration`
   * `certificate` (U/A, A, etc.)
   * `release_date`
   * `description`
   * `poster_url`

3. **Theatre**

   * `theatre_id` (PK)
   * `name`
   * `location` (FK to city)
   * `address`
   * `contact_info`

4. **Screen**

   * `screen_id` (PK)
   * `theatre_id` (FK)
   * `screen_number`
   * `seat_layout` (JSON or separate seat entity)

5. **Show**

   * `show_id` (PK)
   * `movie_id` (FK)
   * `screen_id` (FK)
   * `start_time`
   * `end_time`
   * `date`
   * `language`
   * `price_per_seat`

6. **Seat**

   * `seat_id` (PK)
   * `screen_id` (FK)
   * `seat_number` (e.g., A1, A2)
   * `seat_type` (Normal, Premium, Recliner)

7. **Booking**

   * `booking_id` (PK)
   * `user_id` (FK)
   * `show_id` (FK)
   * `booking_time`
   * `total_amount`
   * `payment_status` (Pending, Paid, Failed)
   * `status` (Confirmed, Cancelled)

8. **Booking\_Seat**

   * Composite key: (`booking_id`, `seat_id`)
   * `price`
   * `is_cancelled`

9. **Payment**

   * `payment_id` (PK)
   * `booking_id` (FK)
   * `payment_method` (UPI, Card, Wallet)
   * `amount`
   * `payment_time`
   * `status` (Success, Failed)

---

###  Location/Support Entities

10. **City**

* `city_id` (PK)
* `name`
* `state`

11. **Language**

* `language_id` (PK)
* `name` (e.g., English, Hindi)

12. **Genre**

* `genre_id` (PK)
* `name` (e.g., Action, Comedy)

13. **Movie\_Genre** (Many-to-many between Movie and Genre)

* `movie_id` (FK)
* `genre_id` (FK)

---

###  Optional / Advanced Entities

14. **Review**

* `review_id` (PK)
* `user_id` (FK)
* `movie_id` (FK)
* `rating` (1 to 5)
* `comment`
* `review_date`

15. **Offer / PromoCode**

* `offer_id` (PK)
* `code`
* `discount_percentage` or `flat_amount`
* `valid_from`
* `valid_to`
* `terms`

16. **Notifications**

* `notification_id` (PK)
* `user_id` (FK)
* `message`
* `created_at`
* `is_read`

---


*/
/*
CREATE TABLE Movie (
    movie_id INT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    duration_minutes INT,
    genre VARCHAR(100)
);

CREATE TABLE Theater (
    theater_id INT PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    location VARCHAR(255)
);

CREATE TABLE Screen (
    screen_id INT PRIMARY KEY,
    theater_id INT,
    screen_name VARCHAR(100),
    total_seats INT,
    FOREIGN KEY (theater_id) REFERENCES Theater(theater_id)
);

CREATE TABLE Show (
    show_id INT PRIMARY KEY,
    movie_id INT,
    screen_id INT,
    start_time DATETIME,
    ticket_price DECIMAL(10, 2),
    FOREIGN KEY (movie_id) REFERENCES Movie(movie_id),
    FOREIGN KEY (screen_id) REFERENCES Screen(screen_id)
);

CREATE TABLE Seat (
    seat_id INT PRIMARY KEY,
    screen_id INT,
    seat_number VARCHAR(10),
    FOREIGN KEY (screen_id) REFERENCES Screen(screen_id)
);

CREATE TABLE Booking (
    booking_id INT PRIMARY KEY,
    user_id INT,
    show_id INT,
    booking_time DATETIME,
    total_amount DECIMAL(10, 2),
    FOREIGN KEY (show_id) REFERENCES Show(show_id)
);

CREATE TABLE BookingSeat (
    booking_seat_id INT PRIMARY KEY,
    booking_id INT,
    seat_id INT,
    FOREIGN KEY (booking_id) REFERENCES Booking(booking_id),
    FOREIGN KEY (seat_id) REFERENCES Seat(seat_id)
);


*/