פרויקט זה הוא מימוש של משחק המונופול באמצעות ספריית הגרפיקה SFML ב-C++. המשחק מאפשר לשחקנים לנוע על לוח המשחק, לרכוש נכסים, לשלם שכר דירה, וביצוע פעולות אחרות במסגרת חוקי המשחק.

תכונות הפרויקט
לוח משחק דינמי: מימוש של לוח משחק עם ערים ורחובות בישראל כמו קריית אתא, אריאל, נתניה, חיפה, ירושלים, תל אביב, וסביון.
תנועת שחקנים: שחקנים יכולים להתקדם בהתאם להטלת קובייה ולהתבצע פעולות כמו קנייה של בתים ומלונות.
ניהול כסף ושכירות: שחקנים מרוויחים כסף ועוברים בין רחובות ומשלמים שכירות בהתאם למיקומם בלוח.
ממשק גרפי: התקשורת עם השחקן מתבצעת דרך ממשק גרפי (GUI) עם חלונות, כפתורים והודעות.
כרטיסי הזדמנות והפתעות: מימוש כרטיסי "צ'אנס" שמשפיעים על המשחק בדרכים בלתי צפויות.
כלא ומס: טיפול בכלא, מיסים ו"חנייה חופשית" בהתאם לחוקי המשחק
מבנה קוד
הפרויקט מחולק למספר מחלקות עיקריות:


 מחלקת GameFlow:
 המחלקה האחראית על שטף המשחקת ניהול תורים, תזוזת שחקנים, בדיקת סטטוס המשחק.
 בנוסף מקיימת אינטרקציה שוטפת עם ממשחק הGUI ומכילה את מתודת updateGUI הדואגת לעדכן לאחר כל הטלה במשחק את מצב הלוח העדכני.
 בנוסף מחלקה זו אחראית על קבלת מספר השחקנים, התאמת צבע ייחודי לכל שחקן בעזרת ממשק הGUI


מחלקת Square: 
מחלקת הבסיס לריבועי הלוח (כולל רחובות נכסים ומשבצות מיוחדות כל המחלקות הנ"ל ממששות את המחלקה.).


מחלקת SpecialSquare: 
מחלקה המייצגת ריבועים מיוחדים כמו כלא, מס, הזדמנות וחנייה חופשית.


מחלקת Player:
מחלקת השחקן דואגת לכל הפעולות ומידע אשר שחקן מחזיק. מחלקה זו מחזיקה את מידע הבסיס אשר כל שחקן מחזיק כגון צבע, שם ומספר זיהוי.
בנוסף מחלקה זו מחזיקה מידע אשר השחקן סופח אליו במהלך משחק, רשימת נכסים(רחובות ותשתיות), רשימת בתים, תשתיות אשר השחקן מחזיק בהם וכרטיסים מיוחדים שיש לשחקן.
המחלקה אחראית גם לממשק ה GUI המקיים אינטרקציה עם Player. כלומר: המחלקה אחראית ליצירה ושינוע על הלוח של הPlayer marker(הסימון של השחקן בלוח), צביעת רחובות
ובתים ובמקרה הצורך וציור כמות הכסף אשר קיים לשחקן בכל עת.


מחלקת Board:
אחראית על יצירת לוח המשחק, וייצוגו ב GUI . מחלקה Singleton כך שיכול להיות רק Board יחיד בכל עת.


מחלקת Button:
מחלקה האחראית על יצירת הכפתור הניתן ללחיצה במהלך המשחק, מחלקות שונות בקוד משתמשות במחלקה זו ליצירת כפתורים לחיצים ואינטרקציה עם המשתמש.


מחלקת Estate:
מחלקה אבסטרקטית המייצגת את הנכסים במשחק הניתנים לקנייה.


מחלקת Street:
מחלקה המייצגת  רחוב הניתן לקנייה מממשת את Estate.
במחלקה זו בנוסף מתקיימת אינטרקציה עם המשתמש אם ברצונו לבצע שדרוג לבית או מלון. 
האינטרקציה הנ"ל מתקיימת בGUI.

מחלקת Infrastrction:
מחלקה המייצגת תשתית הניתנת לקנייה מממשת את Estate: התשתיות הם: חברת חשמל, חברת מים , מסילות רכבת.

הירככית המחלקות:
באופו כללי, כל המחלקות המייצגות משבצת יורשות ממחלקת Square. ההירכיה כלהלן:
מחלקות: SpecialSquare, Estate יורשות באופן ישיר ממחלקת Square.
מחלקות: Street, Infractsture יורשות מ Estate.

מחלקת GameFlow נעזרת בשאר המחלקות על מנת לנהל את המשחק באופן שוטף, על ידי מחלקה זו נשמרת אנקפסולציה של המחלקות האחרות.

מתודה מרכזית במשחק: action, הוגדרה במחלקת Square ולכן כל המחלקות שממשות את Square ממשמשות אותה.

מתודה זו מבצעת פעולה לכל משבצת במשחק, למשל הכנסה לכלא, קניית נכסים, תשלום שכירות וקניית מלונות ובתים.

כך, ממחלקת GameFlow, בעת התמודדות עם משבצת מסוימת רק קריאת Action מתקיימת במחלקה זו.

הפעלת המשחק

בעת הפעלת המשחק, תתבקש להזין את מספר השחקנים (בין 2 ל-8) דרך הממשק הגרפי.
כל שחקן יקבל תור משלו לזרוק את הקוביות ולנוע על הלוח.
בעת מעבר בריבועים שונים, תוצג הודעה על הפעולה הנדרשת, כמו קנייה של רחוב, תשלום שכר דירה, או משיכת כרטיס צ'אנס.
המשחק נמשך עד ששחקן אחד נשאר עם כסף ויתר השחקנים פשטו רגל או לחלופין קיים שחקן המחזיק +4000 שקל.

מדריך GUI:
בתחילת המשחק יופיע מסך היפרט את השלבים להכנסת כל השחקנים למשחק אנא עקבו אחר ההוראות.
הזנת השחקנים תבוצע בפורמט:
שם: הכניסו שם, לחצו Enter.
צבע: הכניסו צבע, לחצו Enter. וכך הלאה לכל שחקן.
בעת תחילת המשחק, הכסף של השחקנים יופיע בלוח.
כמו כן אם תרצו לעיין בנכסים של השחקנים אנא לחצו על VIEW Estates.
על מנת להתחיל לשחק, אנא לחצו על Roll Dice, בהתאם למשבצת שלכם, תדרשו לבצע פעולות מסוימות, הממשק מתקיים
אך ורק בעזרת לחיצת העכבר על מקשים Yes,No,Pay,Roll היופיעו בעת הצורך.
בחלק מההודעות קיים טיימר על מנת להעניק לכם מספיק זמן לקרוא את ההודעה.
אנא בעת זריקת קוביות (Roll dice) המתינו שההודעה תעבור מהמסך.
בדיקת מנצח מתבצעת באופן אוטומטי והפסקת המשחק עקב כך.
בהצלחה!


