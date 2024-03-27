import face_recognition


def face(image_path, known_faces, known_names):
    unknown_image = face_recognition.load_image_file(image_path)
    unknown_face_locations = face_recognition.face_locations(unknown_image)

    if not unknown_face_locations:
        name = "Unknown"
        print(f"Name: {name}")
        print("\n")
        return name

    unknown_face_encodings = face_recognition.face_encodings(unknown_image, unknown_face_locations)

    for face_encoding in unknown_face_encodings:
        matches = face_recognition.compare_faces(known_faces, face_encoding)
        name = "Unknown"

        if True in matches:
            first_match_index = matches.index(True)
            name = known_names[first_match_index]

        print(f"Name: {name}")
        print("\n")
        return name
