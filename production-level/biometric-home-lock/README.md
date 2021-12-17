# Biometric Home Lock

We created Lockplus to simulate a biometric facial-recognition lock. Lockplus has two-components, a website and a raspberry pi to simulate a "lock". Through our website, users can register an account and upload images of their faces as well as faces of other users they want to be able to access their lock. From there, the uploaded images are stored in our MongoDB database to be fetched by the raspberry pi in real-time, which then trains those images to their respective user using its facial-recognition model. Registered users can face the raspberry pi's camera and press a button to "scan" their face and be granted access.

In addition, every unlock attempt (noted by each raspberry pi button press) takes an image which is uploaded to our database and displayed in real-time on our website, stating which user unlocked the lock (will display "unknown" for failed attempt), as well as the image taken during the attempt and the time and date it was taken.

Tech Stack:
-Website: Next.js, MongoDB, TypeScript
-Lock: Python, Raspberry Pi

Core Libraries:
-Website: SWR, NextAuth, TailwindCSS, Mongoose, Multer, Nodemailer
-Lock: pyMongo, face_recognition

Collaborators:

Hoang Ha
LinkedIn: https://www.linkedin.com/in/hoangha98/
GitHub:

Michael Yang
LinkedIn: https://www.linkedin.com/in/michael-yang-51005419b/
GitHub: https://github.com/michaelyang12
