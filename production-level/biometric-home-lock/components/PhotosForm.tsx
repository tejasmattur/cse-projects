import React, { useCallback, useState } from 'react';
import { AddPhotoButton } from './photos_page/AddPhotoButton';
import { useSession } from 'next-auth/react';
import slugify from 'slugify';
import axios from 'axios';
import { useRouter } from 'next/router';
import Loader from 'react-loader-spinner';
import 'react-loader-spinner/dist/loader/css/react-spinner-loader.css';

/*
interface Response {
  status: boolean;
  message: string;
  statusText: string;
  code: any;
}
*/

export const PhotosForm = (props) => {
  const router = useRouter();
  const sessionEmail = props.sessionEmail;
  const safeUser: string = slugify(props.user ?? '', {
    remove: /[^\w_\-]/g,
  });
  //const safeUser = encodeURIComponent(props.user);
  console.log('user');
  console.log(safeUser);
  //const [uploadSuccess, setUploadSuccess] = useState('');

  const [isRefreshing, setIsRefreshing] = React.useState(false);

  /*
  function refreshData() {
    router.replace('/users');
  }*/

  React.useEffect(() => {
    setIsRefreshing(false);
  }, [props]);

  var loadVisibility = isRefreshing ? 'visible' : 'invisible';

  var messageVisibility = !isRefreshing ? 'visible' : 'invisible';

  const onChange = async (formData) => {
    setIsRefreshing(true);
    const config = {
      headers: { 'content-type': 'multipart/form-data' },
      onUploadProgress: (event) => {
        console.log(
          `Current progress:`,
          Math.round((event.loaded * 100) / event.total)
        );
      },
    };
    console.log('code');
    const code: string = props.code;
    console.log(code);
    const apiUrl: string = '/api/dbPhotos/' + code + '/' + safeUser;
    const response: any = await axios.post(apiUrl, formData, config);
    props.setUploadSuccess(response.data.message);
    router.replace(router.asPath);
    //refreshData();
  };

  return (
    <div>
      <AddPhotoButton
        label="Upload Photos"
        uploadFileName="theFiles"
        onChange={onChange}
      />
      <div
        className={`${loadVisibility} mt-4 ml-36 font-lockplus font-md text-gray-700 text-md w-64`}>
        Uploading...
        <div className="absolute top-0 mt-4 ml-24">
          <Loader
            type="TailSpin"
            color="#00BFFF"
            height={25}
            width={25}
            visible={isRefreshing}
          />
        </div>
      </div>
      <div
        className={`${messageVisibility} absolute -ml-48 -pl-8 mt-6 h-12 whitespace-nowrap text-left text-gray-700 font-lockplus font-md text-red-500 text-md w-full`}>
        {props.uploadSuccess}
      </div>
    </div>
  );
};
