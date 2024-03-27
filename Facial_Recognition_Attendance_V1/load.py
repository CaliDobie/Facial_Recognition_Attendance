import os
import face_recognition


def saved_known_faces(known_faces_folder):
    known_faces = []
    known_names = []

    for filename in os.listdir(known_faces_folder):
        if filename.endswith(('.jpg', '.png')):
            face_image = face_recognition.load_image_file(os.path.join(known_faces_folder, filename))
            face_encoding = face_recognition.face_encodings(face_image)[0]
            known_faces.append(face_encoding)
            known_names.append(os.path.splitext(filename)[0])

    return known_faces, known_names
