/*
Calendar calendar = Calendar.getInstance();

        int minute = calendar.get(Calendar.MINUTE);
        int hour = calendar.get(Calendar.HOUR);
        System.out.println("Ваше время: " + hour + minute);

        System.out.println(calendar.get(Calendar.DAY_OF_MONTH));
        calendar.add(Calendar.DAY_OF_MONTH, 15);
        System.out.println(calendar.get(Calendar.DAY_OF_MONTH));

        System.out.println(calendar.get(Calendar.SECOND) + ":" + calendar.get(Calendar.MINUTE) + ":" + calendar.get(Calendar.HOUR));
        calendar.clear(); // Clear the calendar
        System.out.println(calendar.get(Calendar.SECOND) + ":" + calendar.get(Calendar.MINUTE) + ":" + calendar.get(Calendar.HOUR));

        calendar.add(Calendar.MINUTE, 50);
        System.out.println(calendar.get(Calendar.SECOND) + ":" + calendar.get(Calendar.MINUTE) + ":" + calendar.get(Calendar.HOUR));

        System.out.println(calendar.getTime());

        System.out.println(calendar.get(Calendar.YEAR));
        calendar.set(Calendar.YEAR, 2000);
        System.out.println(calendar.get(Calendar.YEAR));

        // LocalTime localTime = LocalTime.now();

        // ZonedDateTime zonedDateTime = ZonedDateTime.of(LocalDateTime.of(2022, 11, 23, 14, 47), ZoneId.of("Asia/Almaty"));
        //System.out.println(localTime);
        // System.out.println(zonedDateTime);
        System.out.println(ZoneId.systemDefault());

        System.out.println("");
        System.out.println(ZoneId.getAvailableZoneIds());


        //System.out.println(localTime.getHour());

        System.out.println("");
        LocalTime localTime = LocalTime.now(); //Содержит только врем
        System.out.println(localTime);
        localTime.plusHours(2);
        LocalTime newLocalTime = localTime.plusHours(5);
        System.out.println("Старое время: " + localTime);
        System.out.println("Новое время: " + newLocalTime);
        localTime = localTime.plusHours(3);
        System.out.println("Обновленное старое время: " + localTime);


        Period period = Period.of(2000, 12, 5);
        System.out.println(period);

        Date date = new Date();
        System.out.println(date);

        Instant instant = date.toInstant();

        ZonedDateTime zonedDateTime = instant.atZone(ZoneId.of("Asia/Almaty"));
        System.out.println(zonedDateTime);


 */