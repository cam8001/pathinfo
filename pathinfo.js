Drupal.behaviors.pathinfo = function(context) {
  // Catch the submit action of the main form (at admin/settings/pathinfo)
  $('form#pathinfo-lookup-form', context).submit(function(){
    var path = $('input[name=path]', this).val();
    // need to encode this url 
    var url = Drupal.settings.basePath + 'admin/settings/pathinfo/ajax/' + '?path=' + encodeURI(path);
    console.log(url);
    //return false;
    $.getJSON(url, function(result){
      $('#pathinfo-result').html(result.data);
      console.log(result);
    });
    
    /*
     
     $.get({
      url: url,
      type: 'GET',
      success = function() {
      },
      error = function() {
      },
     });
     
     */
    
    //console.log(this);
    return false;
  });
}


