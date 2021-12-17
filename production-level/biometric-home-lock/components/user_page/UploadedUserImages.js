import React, { useState, useEffect, useMemo, useCallback } from 'react';
import axios from 'axios';
import Image from 'next/image';
import { useRouter } from 'next/router';
import Loader from 'react-loader-spinner';
import 'react-loader-spinner/dist/loader/css/react-spinner-loader.css';

function UploadedUserImages(props) {
  const router = useRouter();
  var visibility = props.isUserSelected ? 'visible' : 'invisible';
  const image = props.image;
  const [source, setSource] = useState('');
  const [apiDone, setApiDone] = useState(false);
  const email = props.email;
  console.log(image);

  const [isRefreshing, setIsRefreshing] = useState(false);

  const refreshData = () => {
    router.replace(router.asPath);
  };

  useEffect(() => {
    setIsRefreshing(false);
  }, [props]);

  var visibility = isRefreshing ? 'visible' : 'invisible';

  useMemo(() => {
    setApiDone(false);
    console.log('is this even working?');
    axios
      .post(`/api/singlephoto/${image.filename}`, {
        email: email,
      })
      .catch((err) => console.log(err))
      .then((response) => {
        console.log('response');
        // console.log(response.data);
        if (response) {
          setSource(
            `data:${response.data.cType};base64,${Buffer.from(
              response.data.buffer
            ).toString('base64')}`)
          setApiDone(true);
        }
      });
  }, [props.image]);

  function deleteImg(e) {
    setIsRefreshing(true);
    e.preventDefault();
    console.log('delete image call');
    axios
      .post('/api/deletephoto', {
        email: email,
        filename: image.filename,
      })
      .catch((err) => console.log(err))
      .then((response) => {
        console.log(response);
        if (response) {
          refreshData();
          console.log("Delete: ****")
          console.log(image.filename)
        }
      });
  }

  return (
    <>
      {apiDone ? (
        <div className="h-full w-full relative">
          <div className="h-full w-full">
            <Image
              src={source}
              alt="something went wrong"
              className="object-cover"
              width={190}
              height={190}
            />
            <div
              class={`${visibility} absolute -top-0 h-48 w-48 opacity-80 bg-gray-800 font-md text-white font-regular font-lockplus`}>
              <div class="mt-12 ml-14">
                Deleting...
                <Loader
                  type="TailSpin"
                  color="#FFFFFF"
                  height={70}
                  width={70}
                  visible={isRefreshing}
                />
              </div>
            </div>
          </div>
          <button
            className="absolute top-0 right-0 mr-4 rounded-bl-sm text-xs text-red-500 font-lockplus hover:text-red-700 focus:outline-none"
            onClick={deleteImg}>
            X
          </button>
        </div>
      ) : (
        <div className="h-full w-full relative">
          <div
            class={`visible absolute -top-0 h-48 w-48 opacity-40 bg-gray-800 font-md text-white font-regular font-lockplus`}>
            <div class="mt-12 ml-14">
              Loading...
              <Loader
                type="TailSpin"
                color="#FFFFFF"
                height={70}
                width={70}
                visible={true}
              />
            </div>
          </div>
        </div>
      )}
    </>
  );
}

export default UploadedUserImages;
