/*Name this external file gallery.js*/

function upDate(previewPic) {
    /* In this function you should 
       1) change the url for the background image of the div with the id = "image" 
       to the source file of the preview image
       
       2) Change the text  of the div with the id = "image" 
       to the alt text of the preview image 
       */
       let imageDiv = document.getElementById("image");
       imageDiv.style.backgroundImage = `url(${previewPic.src})`;
       imageDiv.innerHTML = previewPic.alt
}

function unDo() {
    /* In this function you should 
   1) Update the url for the background image of the div with the id = "image" 
   back to the orginal-image.  You can use the css code to see what that original URL was
   
   2) Change the text  of the div with the id = "image" 
   back to the original text.  You can use the html code to see what that original text was
   */
   let imageDiv = document.getElementById("image");
   imageDiv.style.backgroundImage = "url('')";
   imageDiv.innerHTML = "Hover over an image below to display here.";

}

function gallery(){
    console.log("Gallery initialized!");

    // Add tabindex attribute and onfocus/onblur event listeners to all preview images
    const previews = document.querySelectorAll(".preview");
    for (let i = 0; i < previews.length; i++) {
        previews[i].setAttribute("tabindex", "0");

        // Add mouse events
        previews[i].addEventListener("mouseover", function () {
            upDate(previews[i]);
        });
        previews[i].addEventListener("mouseleave", unDo);

        // Add keyboard focus events
        previews[i].addEventListener("focus", function () {
            upDate(previews[i]);
        });
        previews[i].addEventListener("blur", unDo);
    }
}